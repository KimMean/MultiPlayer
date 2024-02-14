#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Components/Enemy/EnemyStateComponent.h"
#include "EnemyAnimationData.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FEnemyAnimData
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere)
		TArray<TObjectPtr<UAnimMontage>> AnimationMontage;
};

UCLASS()
class MULTIPLAYER_API UEnemyAnimationData : public UDataAsset
{
	GENERATED_BODY()
	
public :
	FEnemyAnimData GetAnimationData(const EEnemyStateType& InEnemyStateType);
	TObjectPtr<UAnimMontage> GetAnimationMontageData(const EEnemyStateType& InEnemyStateType);

protected :
	UPROPERTY(EditAnywhere)
		TMap<EEnemyStateType, FEnemyAnimData> AnimationDatas;
};
