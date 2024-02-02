#include "MultiPlayerGameMode.h"

#include "GameSetting/Controllers/ControllerBase.h"
#include "GameSetting/PlayerState/PlayerStateBase.h"
#include "GameSetting/GameState/StateBase.h"
#include "GameSetting/HUD/HUDBase.h"
#include "GameSetting/GameSession/GameSessionBase.h"
#include "GameSetting/Spectator/SpectatorBase.h"

#include "Utilities/DebugLog.h"

AMultiPlayerGameMode::AMultiPlayerGameMode()
{
	DefaultPawnClass = ADefaultPawn::StaticClass();
	PlayerControllerClass = AControllerBase::StaticClass();
	PlayerStateClass = APlayerStateBase::StaticClass();
	GameStateClass = AStateBase::StaticClass();
	HUDClass = AHUDBase::StaticClass();
	GameSessionClass = AGameSessionBase::StaticClass();
	SpectatorClass = ASpectatorBase::StaticClass();
	ReplaySpectatorPlayerControllerClass = AControllerBase::StaticClass();
	ServerStatReplicatorClass = AServerStatReplicator::StaticClass();
}

void AMultiPlayerGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	DebugLog::Print("InitGame");
	Super::InitGame(MapName, Options, ErrorMessage);
}

void AMultiPlayerGameMode::InitGameState()
{
	DebugLog::Print("InitGameState");
	Super::InitGameState();
}

void AMultiPlayerGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	DebugLog::Print("PreLogin");
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
}

APlayerController* AMultiPlayerGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	DebugLog::Print("Login");
	return Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
}

void AMultiPlayerGameMode::PostLogin(APlayerController* NewPlayer)
{
	DebugLog::Print("PostLogin");
	Super::PostLogin(NewPlayer);
}

void AMultiPlayerGameMode::OnPostLogin(AController* NewPlayer)
{
	DebugLog::Print("OnPostLogin");
	Super::OnPostLogin(NewPlayer);
}


void AMultiPlayerGameMode::Logout(AController* Exiting)
{
	DebugLog::Print("Logout");
	Super::Logout(Exiting);
}

void AMultiPlayerGameMode::BeginPlay()
{
	Super::BeginPlay();
}