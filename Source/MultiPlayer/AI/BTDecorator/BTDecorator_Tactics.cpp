#include "AI/BTDecorator/BTDecorator_Tactics.h"

#include "GameSetting/Controllers/AIControllerBase.h"
#include "Characters/Enemies/EnemyBase.h"

#include "Utilities/UsefulMath.h"
#include "Utilities/DebugLog.h"

UBTDecorator_Tactics::UBTDecorator_Tactics()
{
	NodeName = TEXT("Tactics");
}

bool UBTDecorator_Tactics::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	TObjectPtr<AAIControllerBase> controller = Cast<AAIControllerBase>(OwnerComp.GetOwner());
	TObjectPtr<AEnemyBase> enemy = Cast<AEnemyBase>(controller->GetPawn());
	//TObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(controller->GetPawn());

	// 가중치에 따라 캐릭터 상태를 결정합니다.
	
	TArray<float> weights;
	for (FTacticalData data : TacticalDatas)
	{
		weights.Add(data.Value);
	}

	int32 tacticsIndex = UsefulMath::WeightedRandomIndex(weights);

	enemy->GetCharacterStateComponent()->SetCharacterState(TacticalDatas[tacticsIndex].State);
	
	return true;
}
