#include "GameSetting/GameSession/GameSessionBase.h"

#include "Utilities/DebugLog.h"

AGameSessionBase::AGameSessionBase()
{
}

void AGameSessionBase::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	DebugLog::Print("AGameSessionBase : PostLogin");
	DebugLog::Print("AGameSessionBase : SessionName : ");
	DebugLog::Print(MaxPlayers);
}

void AGameSessionBase::NotifyLogout(const APlayerController* PC)
{
	Super::NotifyLogout(PC);
	DebugLog::Print("AGameSessionBase : NotifyLogout");
}

void AGameSessionBase::NotifyLogout(FName InSessionName, const FUniqueNetIdRepl& UniqueId)
{
	Super::NotifyLogout(InSessionName, UniqueId);
	DebugLog::Print("AGameSessionBase : NotifyLogout");
}

void AGameSessionBase::RegisterPlayer(APlayerController* NewPlayer, const FUniqueNetIdRepl& UniqueId, bool bWasFromInvite)
{
	Super::RegisterPlayer(NewPlayer, UniqueId, bWasFromInvite);
	DebugLog::Print("AGameSessionBase : RegisterPlayer");
}

void AGameSessionBase::UnregisterPlayer(FName InSessionName, const FUniqueNetIdRepl& UniqueId)
{
	Super::UnregisterPlayer(InSessionName, UniqueId);
	DebugLog::Print("AGameSessionBase : UnregisterPlayer");
}

void AGameSessionBase::UnregisterPlayers(FName InSessionName, const TArray<FUniqueNetIdRepl>& Players)
{
	Super::UnregisterPlayers(InSessionName, Players);
	DebugLog::Print("AGameSessionBase : UnregisterPlayers");
}

void AGameSessionBase::UnregisterPlayer(const APlayerController* ExitingPlayer)
{
	Super::UnregisterPlayer(ExitingPlayer);
	DebugLog::Print("AGameSessionBase : UnregisterPlayer");
}

void AGameSessionBase::OnStartSessionComplete(FName InSessionName, bool bWasSuccessful)
{
	Super::OnStartSessionComplete(InSessionName, bWasSuccessful);
	DebugLog::Print("AGameSessionBase : OnStartSessionComplete");
}

void AGameSessionBase::OnEndSessionComplete(FName InSessionName, bool bWasSuccessful)
{
	Super::OnEndSessionComplete(InSessionName, bWasSuccessful);
	DebugLog::Print("AGameSessionBase : OnEndSessionComplete");
}
