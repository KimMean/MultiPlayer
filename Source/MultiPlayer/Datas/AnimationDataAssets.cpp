#include "Datas/AnimationDataAssets.h"


TObjectPtr<UAnimMontage> UAnimationDataAssets::GetAnimationMontageRandomData(ECharacterState InStateType)
{
	if (!AnimationDatas.Contains(InStateType)) return nullptr;

	//const FAnimationData Datas = GetAnimationData(InStateType);
	//const TArray<TObjectPtr<UAnimMontage>> MontageData = Datas.AnimationMontage;
	const TArray<TObjectPtr<UAnimMontage>> MontageData = GetAnimationMontageDatas(InStateType);

	if (MontageData.Num() == 0) return nullptr;

	int32 randNum = FMath::RandRange(0, MontageData.Num() - 1);

	return GetAnimationMontageData(MontageData, randNum);
}

TObjectPtr<UAnimMontage> UAnimationDataAssets::GetAnimationMontageData(ECharacterState InStateType, int32 InIndex)
{
	if (!AnimationDatas.Contains(InStateType)) return nullptr;

	//const FAnimationData Datas = GetAnimationData(InStateType);
	//const TArray<TObjectPtr<UAnimMontage>> MontageData = Datas.AnimationMontage;
	const TArray<TObjectPtr<UAnimMontage>> MontageData = GetAnimationMontageDatas(InStateType);

	if (MontageData.Num() == 0) return nullptr;
	if (MontageData.Num() <= InIndex) return nullptr;

	return GetAnimationMontageData(MontageData, InIndex);
}

TObjectPtr<UAnimMontage> UAnimationDataAssets::GetAnimationMontageData(const TArray<TObjectPtr<UAnimMontage>>& InMontageData, int32 InIndex)
{
	return InMontageData[InIndex];
}

FAnimationData UAnimationDataAssets::GetAnimationData(ECharacterState InStateType)
{
	return AnimationDatas[InStateType];
}

const TArray<TObjectPtr<UAnimMontage>> UAnimationDataAssets::GetAnimationMontageDatas(ECharacterState InStateType)
{
	return GetAnimationData(InStateType).AnimationMontage;
}
