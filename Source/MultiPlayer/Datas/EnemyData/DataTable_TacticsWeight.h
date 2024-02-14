#pragma once

#include "CoreMinimal.h"
#include "UObject/object.h"
#include "Characters/Enemies/EnemyBase.h"
#include "DataTable_TacticsWeight.generated.h"

USTRUCT(BlueprintType)
struct FTacticsWeightData : public FTableRowBase
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere)
		EEnemyType EnemyType = EEnemyType::NONE;

	UPROPERTY(EditAnywhere)
		float AttackWeight = 1.0f;

	UPROPERTY(EditAnywhere)
		float DefendWeight = 1.0f;

	UPROPERTY(EditAnywhere)
		float EvadeWeight = 1.0f;
};

UCLASS()
class MULTIPLAYER_API UDataTable_TacticsWeight : public UObject
{
	GENERATED_BODY()
};
