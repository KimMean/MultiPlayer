#include "System/OnlineSubsystem/SteamSystem.h"

#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"
#include "Online/OnlineSessionNames.h"
#include "Kismet/GameplayStatics.h"

#include "Utilities/DebugLog.h"

USteamSystem::USteamSystem()
{
	// OnlineSubsystem�� Access
	IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get();
	if (OnlineSubsystem)
	{
		// �¶��� ���� �޾ƿ���
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

	// �̹� ������ �����Ѵٸ� ���� ������ �����Ѵ�
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

	// ���� ���� �Ϸ� �� ȣ��� delegate ����Ʈ�� CreateSessionCompleteDelegate �߰�
	OnlineSessionInterface->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteDelegate);

	// ���� �����ϱ�
	TSharedPtr<FOnlineSessionSettings> SessionSettings = MakeShareable(new FOnlineSessionSettings());

	SessionSettings->bIsLANMatch = false;			// LAN ����
	SessionSettings->NumPublicConnections = 4;		// �ִ� ���� ���� ��
	SessionSettings->bAllowJoinInProgress = true;	// Session �����߿� ���� ���
	SessionSettings->bAllowJoinViaPresence = true;	// ���� ���� ������ ���� �������� ���� (������ presence ���)
	SessionSettings->bShouldAdvertise = true;		// ���� ������ �������� (������ �ٸ� �÷��̾�� ���� ȫ�� ����)
	SessionSettings->bUsesPresence = true;			// ���� ������ ���� ǥ��
	SessionSettings->bUseLobbiesIfAvailable = true; // �÷����� �����ϴ� ��� �κ� API ���
	SessionSettings->Set(FName("MatchType"), FString("FreeForAll"), EOnlineDataAdvertisementType::ViaOnlineServiceAndPing);

	// FOnlineSessionSettings�� Set�Լ��� SessionSetting�� �� Key�� Value ¦���� �ɼ��� �������ִ� �Լ���.	�� �ڵ�� ������ MatchType�� '��ο��� ����(FreeForAll)'���� �����ϰ�, �¶��� ���񽺿� ���� ���� ������ ȫ���� �� �ְ� �����ϴ� �ڵ��̴�.

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	OnlineSessionInterface->CreateSession(*LocalPlayer->GetPreferredUniqueNetId(), NAME_GameSession, *SessionSettings);
}

void USteamSystem::JoinSession()
{
	// ���� �������̽� ��ȿ�� �˻�
	if (!OnlineSessionInterface.IsValid())
	{
		// log
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString(TEXT("Game Session Interface is invailed")));
		}
		return;
	}

	// Find Session Complete Delegate ���
	OnlineSessionInterface->AddOnFindSessionsCompleteDelegate_Handle(FindSessionCompleteDelegate);

	// Find Game Session
	SessionSearch = MakeShareable(new FOnlineSessionSearch());
	SessionSearch->MaxSearchResults = 10000;	// �˻� ����� ������ ���� �� �ִ밪
	SessionSearch->bIsLanQuery = false;			// LAN ��� ����
	SessionSearch->QuerySettings.Set(SEARCH_PRESENCE, true, EOnlineComparisonOp::Equals); // ã�� ���� ������ ����� �����Ѵ�
	// SEARCH_PRESENCE = "Online/OnlineSessionNames.h"

	const ULocalPlayer* LocalPlayer = GetWorld()->GetFirstLocalPlayerFromController();
	OnlineSessionInterface->FindSessions(*LocalPlayer->GetPreferredUniqueNetId(), SessionSearch.ToSharedRef());
}

void USteamSystem::OnCreateSessionComplate(FName SessionName, bool bWasSuccessful)
{
	// ���� ���� ����!
	if (bWasSuccessful)
	{
		DebugLog::Print("Created session");
		DebugLog::Print(*SessionName.ToString());
		//UGameplayStatics::OpenLevel(GetWorld(), FName("Lobby"), true, ((FString)(L"Listen")));
		GetWorld()->ServerTravel("/Game/Levels/Lobby?Listen");

	}
	else  // ���� ���� ����
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

		// ��ġ Ÿ�� Ȯ���ϱ�
		FString MatchType;
		Result.Session.SessionSettings.Get(FName("MatchType"), MatchType);

		// ã�� ������ ���� ����ϱ�
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Session ID : %s / Owner : %s"), *Id, *User));
		}

		// ������ ��ġ Ÿ���� "FreeForAll"�� ��� ���� ����
		if (MatchType == FString("FreeForAll"))
		{
			if (GEngine)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Cyan, FString::Printf(TEXT("Joining Match Type : %s"), *MatchType));
			}

			// Join Session Complete Delegate ��� 
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
	// ���ǿ� �����ߴٸ� IP Address���ͼ� �ش� ������ ����
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
