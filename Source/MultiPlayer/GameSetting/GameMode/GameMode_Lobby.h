#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode_Lobby.generated.h"


UCLASS()
class MULTIPLAYER_API AGameMode_Lobby : public AGameModeBase
{
	GENERATED_BODY()
	
public :
	AGameMode_Lobby();

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

protected :
	virtual void BeginPlay() override;

};
