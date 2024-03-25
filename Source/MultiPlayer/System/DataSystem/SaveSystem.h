#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Definitions/PlayerDefinition.h"
#include "Characters/CharacterInformation.h"
#include "SaveSystem.generated.h"

UCLASS()
class MULTIPLAYER_API USaveSystem : public USaveGame
{
	GENERATED_BODY()
	
public :
	USaveSystem();

	UPROPERTY(VisibleAnywhere)
		FString SlotName;

	UPROPERTY(VisibleAnywhere)
		uint32 UserIndex;

	UPROPERTY(VisibleAnywhere)
		EPlayerClass PlayerClass;

	UPROPERTY(VisibleAnywhere)
		FCharacterStatus PlayerStatus;


};
