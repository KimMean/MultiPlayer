#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterState.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	//None,
	Idle,
	Move,
	Attack,
	Smash,
	Hit,
	Evation,
	Death,
};

UENUM(BlueprintType)
enum class EMoveState : uint8
{
	None,
	Walk,
	Jog,
	Run,
};

UCLASS()
class MULTIPLAYER_API UCharacterState : public UObject
{
	GENERATED_BODY()

public:
	UCharacterState();

	static FString ToString(ECharacterState Value);
	static void PrintString(ECharacterState Value, float Time, FColor Color);
};
