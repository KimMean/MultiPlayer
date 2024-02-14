#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DirectionState.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EDirectionState : uint8
{
	None,
	Front,
	Back,
	Left,
	Right,
	FrontLeft,
	FrontRight,
	BackLeft,
	BackRight,
	Up,
	Down,
};

UCLASS()
class MULTIPLAYER_API UDirectionState : public UObject
{
	GENERATED_BODY()

public:
	UDirectionState();

	static FString ToString(EDirectionState Value);
	static void PrintString(EDirectionState Value, float Time, FColor Color);
};
