#include "Datas/EnemyData/EnemyAnimationData.h"

#include "Utilities/DebugLog.h"

FEnemyAnimData UEnemyAnimationData::GetAnimationData(const EEnemyStateType& InEnemyStateType)
{
	return AnimationDatas[InEnemyStateType];
}

TObjectPtr<UAnimMontage> UEnemyAnimationData::GetAnimationMontageData(const EEnemyStateType& InEnemyStateType)
{
	const FEnemyAnimData Datas = AnimationDatas[InEnemyStateType];
	const TArray<TObjectPtr<UAnimMontage>> MontageData = Datas.AnimationMontage;

	int32 randNum = FMath::RandRange(0, MontageData.Num()-1);

	return MontageData[randNum];
}
