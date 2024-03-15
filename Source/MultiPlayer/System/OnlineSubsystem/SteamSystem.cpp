#include "System/OnlineSubsystem/SteamSystem.h"

#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Online/OnlineSessionNames.h"
#include "Kismet/GameplayStatics.h"

#include "Utilities/DebugLog.h"

USteamSystem::USteamSystem()
{
	// OnlineSubsystem에 Access
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if (OnlineSubsystem)
	{
		// 온라인 세션 받아오기
		OnlineSessionInterface = OnlineSubsystem->GetSessionInterface();
		CreateSessionCompleteDelegate.BindUObject(this, &USteamSystem::OnCreateSessionComplate);
		FindSessionCompleteDelegate.BindUObject(this, &USteamSystem::OnFindSessionComplate);
		JoinSessionCompleteDelegate.BindUObject(this, &USteamSystem::OnJoinSessionComplate);

		//DebugLog::Print("Create Online Sub System");
		//DebugLog::Print(*OnlineSubsystem->GetSubsystemName().ToString());
	}
}

void USteamSystem::CreateSession()
{
	// Called when pressing the 1key
	if (!OnlineSessionInterface.IsValid())
	{
		// log
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString(TEXT("Game Session is invailed")));
		}
		return;
	}

	// 이미 세션이 존재한다면 기존 세션을 삭제한다
	auto ExistingSession = OnlineSessionInterface->GetNamedSession(NAME_GameSession);
	if (ExistingSession != nullptr)
	{
		OnlineSessionInterface->DestroySession(NAME_GameSession);

		// Log
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Black, FString::Printf(TEXT("Destroy session : %s"), NAME_GameSession));
		}
	}

	// 세션 생성 완료 후 호출될 delegate 리스트에 CreateSessionCompleteDelegate 추가
	OnlineSessionInterface->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegate);

	// 세션 세팅하기
	TSharedPtr<FOnlineSessionSettings> SessionSettings = MakeShareable(new FOnlineSessionSettings());

	SessionSettings->bIsLANMatch = false;			// LAN 연결
	SessionSettings->NumPublicConnections = 4;		// 최대 접속 가능 수
	SessionSettings->bAllowJoinInProgress = true;	// Session 진행중에 접속 허용
	SessionSettings->bAllowJoinViaPresence = true;	// 세션 참가 지역을 현재 지역으로 제한 (스팀의 presence 사용)
	SessionSettings->bShouldAdvertise = true;		// 현재 세션을 광고할지 (스팀의 다른 플레이어에게 세션 홍보 여부)
	SessionSettings->bUsesPresence = true;			// 현재 지역에 세션 표시
	SessionSettings->bUseLobbiesIfAvailable = true; // 플랫폼이 지원하는 경우 로비 API 사용
	SessionSettings->Set(FName("MatchType"), FString("FreeForAll"), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	// FOnlineSessionSettings의 Set함수는 SessionSetting할 때 Key와 Value 짝으로 옵션을 세팅해주는 함수다.	위 코드는 세션의 MatchType을 '모두에게 열림(FreeForAll)'으로 설정하고, 온라인 서비스와 핑을 통해 세션을 홍보할 수 있게 설정하는 코드이다.

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	OnlineSessionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *SessionSettings);
}

void USteamSystem::JoinSession()
{
	// 세션 인터페이스 유효성 검사
	if (!OnlineSessionInterface.IsValid())
	{
		// log
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString(TEXT("Game Session Interface is invailed")));
		}
		return;
	}

	// Find Session Complete Delegate 등록
	OnlineSessionInterface->AddOnFindSessionsCompleteDelegate_Handle(FindSessionCompleteDelegate);

	// Find Game Session
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	SessionSearch->MaxSearchResults = 10000;	// 검색 결과로 나오는 세션 수 최대값
	SessionSearch->bIsLanQuery = false;			// LAN 사용 여부
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals); // 찾을 세션 쿼리를 현재로 설정한다
	// SEARCH_PRESENCE = "Online/OnlineSessionNames.h"

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	OnlineSessionInterface->FindSessions(*LocalPlayer->GetPreferredUniqueNetId(), SessionSearch.ToSharedRef());
}

void USteamSystem::OnCreateSessionComplate(FName SessionName, bool bWasSuccessful)
{
	// 세션 생성 성공!
	if (bWasSuccessful)
	{
		DebugLog::Print("Created session");
		DebugLog::Print(*SessionName.ToString());
		//UGameplayStatics::OpenLevel(GetWorld(), FName("Lobby"), true, ((FString)(L"Listen")));
		GetWorld()->ServerTravel("/Game/Levels/Lobby?Listen");

	}
	else  // 세선 생성 실패
	{
		DebugLog::Print("Failed to create session!");
	}
}

void USteamSystem::OnFindSessionComplate(bool bWasSuccessful)
{
	if (!OnlineSessionInterface.IsValid()
		|| !bWasSuccessful)
		return;

	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString(TEXT("======== Search Result ========")));
	}

	for (auto Result : SessionSearch->SearchResults)
	{
		FString Id = Result.GetSessionIdStr();
		FString User = Result.Session.OwningUserName;

		// 매치 타입 확인하기
		FString MatchType;
		Result.Session.SessionSettings.Get(FName("MatchType"), MatchType);

		// 찾은 세션의 정보 출력하기
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Session ID : %s / Owner : %s"), *Id, *User));
		}

		// 세션의 매치 타입이 "FreeForAll"일 경우 세션 참가
		if (MatchType == FString("FreeForAll"))
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Joining Match Type : %s"), *MatchType));
			}

			// Join Session Complete Delegate 등록 
			OnlineSessionInterface->AddOnJoinSessionCompleteDelegate_Handle(JoinSessionCompleteDelegate);


			const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
			OnlineSessionInterface->JoinSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, Result);
			
		}
	}
}

void USteamSystem::OnJoinSessionComplate(FName SessionName, EOnJoinSessionCompleteResult::Type Result)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Joining Session Complate : %s"), *SessionName.ToString()));
	}
	// 세션에 조인했다면 IP Address얻어와서 해당 서버에 접속
	FString Address;
	if (OnlineSessionInterface->GetResolvedConnectString(SessionName, Address))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, FString::Printf(TEXT("Connect String : %s"), *Address));
		}

		APlayerController* PlayerController = GetGameInstance()->GetFirstLocalPlayerController();
		if (PlayerController)
		{
			PlayerController->ClientTravel(Address, ETravelType::TRAVEL_Absolute);
			DebugLog::Print("ClientTravel");
		}
	}
}
