#include "AI/BTDecorator/BTD_CanAttack.h"

#include "GameSetting/Controllers/AIControllerBase.h"
#include "Characters/Enemies/EnemyBase.h"

UBTD_CanAttack::UBTD_CanAttack()
{
	NodeName = TEXT("CanAttack");
}

bool UBTD_CanAttack::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	TObjectPtr<AAIControllerBase> controller = Cast<AAIControllerBase>(OwnerComp.GetOwner());
	TObjectPtr<AEnemyBase> enemy = Cast<AEnemyBase>(controller->GetPawn());

	TObjectPtr<AActor> target = controller->GetTargetActor();
	float distance = enemy->GetDistanceTo(target);

	if (distance <= controller->GetActionRange())
	{
		return true;
	}

	return false;
}
