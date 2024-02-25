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
	/* Randomly Return animation montage data from AnimationDatas */
	TObjectPtr<UAnimMontage> GetAnimationMontageRandomData(ECharacterState InStateType);
	/* Return animation montage data from AnimationDatas */
	TObjectPtr<UAnimMontage> GetAnimationMontageData(ECharacterState InStateType, int32 InIndex = 0);

private :
	/* Return animation montage data from AnimationDatas */
	TObjectPtr<UAnimMontage> GetAnimationMontageData(const TArray<TObjectPtr<UAnimMontage>>& InMontageData, int32 InIndex);
	/* Return FAnimationData from AnimationDatas */
	FAnimationData GetAnimationData(ECharacterState InStateType);
	/* Return TArray<TObjectPtr<UAnimMontage>>& from AnimationDatas */
	const TArray<TObjectPtr<UAnimMontage>> GetAnimationMontageDatas(ECharacterState InStateType);


protected:
	UPROPERTY(EditAnywhere)
		TMap<ECharacterState, FAnimationData> AnimationDatas;
};
