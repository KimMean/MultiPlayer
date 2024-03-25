#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "InitializedGameMode.generated.h"

UCLASS()
class MULTIPLAYER_API AInitializedGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AInitializedGameMode();

	// ~ Begin AGameModeBase Interface
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	virtual void InitGameState() override;

	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void OnPostLogin(AController* NewPlayer) override;


	virtual void Logout(AController* Exiting) override;

	// ~ End AGameModeBase Interface
};
