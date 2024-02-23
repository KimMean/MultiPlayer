#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Enums/CharacterState.h"
#include "AnimationDataAssets.generated.h"

class UAnimMontage;

USTRUCT(BlueprintType)
struct FAnimationData
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
		TArray<TObjectPtr<UAnimMontage>> AnimationMontage;
};

UCLASS()
class MULTIPLAYER_API UAnimationDataAssets : public UDataAsset
{
	GENERATED_BODY()

public:
	FAnimationData GetAnimationData(const ECharacterState& InStateType);
	TObjectPtr<UAnimMontage> GetAnimationMontageData(const ECharacterState& InStateType);

protected:
	UPROPERTY(EditAnywhere)
		TMap<ECharacterState, FAnimationData> AnimationDatas;
};
