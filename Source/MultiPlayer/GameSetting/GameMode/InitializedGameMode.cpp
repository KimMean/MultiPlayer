#include "GameSetting/GameMode/InitializedGameMode.h"

#include "GameSetting/Controllers/ControllerBase.h"
#include "GameSetting/PlayerState/PlayerStateBase.h"
#include "GameSetting/GameState/StateBase.h"
#include "GameSetting/HUD/HUDBase.h"
#include "GameSetting/GameSession/GameSessionBase.h"
#include "GameSetting/Spectator/SpectatorBase.h"
#include "Characters/PawnBase.h"

#include "Utilities/DebugLog.h"

AInitializedGameMode::AInitializedGameMode()
{
	DefaultPawnClass = APawnBase::StaticClass();
	PlayerControllerClass = AControllerBase::StaticClass();
	PlayerStateClass = APlayerStateBase::StaticClass();
	GameStateClass = AStateBase::StaticClass();
	HUDClass = AHUDBase::StaticClass();
	GameSessionClass = AGameSessionBase::StaticClass();
	SpectatorClass = ASpectatorBase::StaticClass();
	ReplaySpectatorPlayerControllerClass = AControllerBase::StaticClass();
	ServerStatReplicatorClass = AServerStatReplicator::StaticClass();
}

void AInitializedGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	DebugLog::Print("InitializedGameMode : InitGame");
}

void AInitializedGameMode::InitGameState()
{
	Super::InitGameState();
	DebugLog::Print("InitializedGameMode : InitGameState");
}

void AInitializedGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	DebugLog::Print("InitializedGameMode : PreLogin");
}

APlayerController* AInitializedGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	DebugLog::Print("InitializedGameMode : Login");
	return Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
}

void AInitializedGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	DebugLog::Print("InitializedGameMode : PostLogin");
}

void AInitializedGameMode::OnPostLogin(AController* NewPlayer)
{
	Super::OnPostLogin(NewPlayer);
	DebugLog::Print("InitializedGameMode : OnPostLogin");
}

void AInitializedGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);
	DebugLog::Print("InitializedGameMode : Logout");
}
