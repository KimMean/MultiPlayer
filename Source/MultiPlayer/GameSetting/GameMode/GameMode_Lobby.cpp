#include "GameSetting/GameMode/GameMode_Lobby.h"

#include "GameSetting/Controllers/LobbyController.h"
#include "Characters/PawnBase.h"

AGameMode_Lobby::AGameMode_Lobby()
{
	PlayerControllerClass = ALobbyController::StaticClass();
	DefaultPawnClass = APawnBase::StaticClass();

}

void AGameMode_Lobby::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void AGameMode_Lobby::InitGameState()
{
	Super::InitGameState();
}

void AGameMode_Lobby::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
}

APlayerController* AGameMode_Lobby::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	return Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
	// Option으로 플레이어 캐릭터의 정보를 받는다.
	// 캐릭터의 정보를 받으면 생성한다.
	// 빙의시킨다. ?

}

void AGameMode_Lobby::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void AGameMode_Lobby::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);

}

void AGameMode_Lobby::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
}

void AGameMode_Lobby::BeginPlay()
{
	Super::BeginPlay();
	
	

}
