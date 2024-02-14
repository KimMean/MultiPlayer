#include "AI/BTTask/BTTN_PlayAnimation.h"

#include "Characters/Enemies/EnemyBase.h"
#include "Components/Enemy/EnemyAnimationComponent.h"
#include "GameSetting/Controllers/AIControllerBase.h"

UBTTN_PlayAnimation::UBTTN_PlayAnimation()
{
	NodeName = "PlayAnimation";
}

EBTNodeResult::Type UBTTN_PlayAnimation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	TObjectPtr<AAIControllerBase> controller = Cast<AAIControllerBase>(OwnerComp.GetOwner());
	TObjectPtr<AEnemyBase> enemy = Cast<AEnemyBase>(controller->GetPawn());
	UEnemyAnimationComponent* animation = enemy->GetEnemyAnimationComponent();

	animation->PlayAnimMontage(StateType);

	return EBTNodeResult::InProgress;
}

void UBTTN_PlayAnimation::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	// Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds); // Empty

	TObjectPtr<AAIControllerBase> controller = Cast<AAIControllerBase>(OwnerComp.GetOwner());
	TObjectPtr<AEnemyBase> enemy = Cast<AEnemyBase>(controller->GetPawn());
	UEnemyStateComponent* state = enemy->GetEnemyStateComponent();

	if(state->IsIdleMode())
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
}
