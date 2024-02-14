#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AttackType.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EAttackType : uint8
{
	Physical,
	Magic,
};

UCLASS()
class MULTIPLAYER_API UAttackType : public UObject
{
	GENERATED_BODY()

public:
	UAttackType();
};
