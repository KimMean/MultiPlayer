#pragma once

#include "CoreMinimal.h"
#include "MultiPlayerGameMode.h"
#include "MainGameMode.generated.h"

UCLASS()
class MULTIPLAYER_API AMainGameMode : public AMultiPlayerGameMode
{
	GENERATED_BODY()
	
public :
	AMainGameMode();

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	
	virtual void InitGameState() override;

	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void OnPostLogin(AController* NewPlayer) override;


	virtual void Logout(AController* Exiting) override;

protected :
	virtual void BeginPlay() override;

};
