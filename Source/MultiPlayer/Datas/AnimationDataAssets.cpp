#include "Datas/AnimationDataAssets.h"

FAnimationData UAnimationDataAssets::GetAnimationData(const ECharacterState& InStateType)
{
	return AnimationDatas[InStateType];
}

TObjectPtr<UAnimMontage> UAnimationDataAssets::GetAnimationMontageData(const ECharacterState& InStateType)
{
	const FAnimationData Datas = AnimationDatas[InStateType];
	const TArray<TObjectPtr<UAnimMontage>> MontageData = Datas.AnimationMontage;

	int32 randNum = FMath::RandRange(0, MontageData.Num() - 1);

	return MontageData[randNum];
}