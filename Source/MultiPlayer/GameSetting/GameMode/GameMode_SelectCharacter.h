#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameMode_SelectCharacter.generated.h"

UCLASS()
class MULTIPLAYER_API AGameMode_SelectCharacter : public AGameModeBase
{
	GENERATED_BODY()
	
public :
	AGameMode_SelectCharacter();

protected :
	void BeginPlay();

public :
	void Travel_CreateCharacter();
};
