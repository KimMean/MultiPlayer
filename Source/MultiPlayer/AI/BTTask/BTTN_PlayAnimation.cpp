#include "AI/BTTask/BTTN_PlayAnimation.h"

#include "Characters/CharacterBase.h"
#include "Characters/Enemies/EnemyBase.h"
#include "Components/StateComponent.h"
#include "Components/AnimationComponent.h"
#include "GameSetting/Controllers/AIControllerBase.h"

#include "Enums/CharacterState.h"
#include "Utilities/DebugLog.h"

UBTTN_PlayAnimation::UBTTN_PlayAnimation()
{
	bNotifyTick = true;
	NodeName = "PlayAnimation";
}

EBTNodeResult::Type UBTTN_PlayAnimation::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	TObjectPtr<AAIControllerBase> controller = Cast<AAIControllerBase>(OwnerComp.GetOwner());
	TObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(controller->GetPawn());
	UAnimationComponent* animation = character->GetAnimationComponent();

	animation->PlayAnimMontageByRandom(StateType);

	return EBTNodeResult::InProgress;
}

void UBTTN_PlayAnimation::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds); // Empty

	TObjectPtr<AAIControllerBase> controller = Cast<AAIControllerBase>(OwnerComp.GetOwner());
	TObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(controller->GetPawn());

	//DebugLog::Print(UCharacterState::ToString(enemy->GetCharacterState()));

	if(character->GetCharacterStateComponent()->GetIsIdleMode())
	{
		FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	}
}
