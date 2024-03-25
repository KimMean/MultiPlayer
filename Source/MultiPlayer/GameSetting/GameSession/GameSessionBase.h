#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "GameSessionBase.generated.h"

UCLASS()
class MULTIPLAYER_API AGameSessionBase : public AGameSession
{
	GENERATED_BODY()
	
public :
	AGameSessionBase();

	// ~ Begin AGameSession Interface
	virtual void PostLogin(APlayerController* NewPlayer) override;
	virtual void NotifyLogout(const APlayerController* PC) override;
	virtual void NotifyLogout(FName InSessionName, const FUniqueNetIdRepl& UniqueId) override;

	virtual void RegisterPlayer(APlayerController* NewPlayer, const FUniqueNetIdRepl& UniqueId, bool bWasFromInvite) override;
	virtual void UnregisterPlayer(FName InSessionName, const FUniqueNetIdRepl& UniqueId) override;
	virtual void UnregisterPlayers(FName InSessionName, const TArray< FUniqueNetIdRepl >& Players) override;
	virtual void UnregisterPlayer(const APlayerController* ExitingPlayer) override;

	virtual void OnStartSessionComplete(FName InSessionName, bool bWasSuccessful) override;
	virtual void OnEndSessionComplete(FName InSessionName, bool bWasSuccessful) override;
	// ~ End AGameSession Interface
};
