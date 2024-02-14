#include "AI/BTDecorator/BTDecorator_AttackTactics.h"

#include "GameSetting/GameInstance/GameInstanceBase.h"
#include "GameSetting/Controllers/AIControllerBase.h"
#include "Components/Enemy/EnemyStateComponent.h"
#include "Characters/Enemies/EnemyBase.h"

#include "Utilities/UsefulMath.h"
#include "Utilities/DebugLog.h"

UBTDecorator_AttackTactics::UBTDecorator_AttackTactics()
{
	NodeName = TEXT("Attack Tactics");
}

bool UBTDecorator_AttackTactics::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	TObjectPtr<AAIControllerBase> controller = Cast<AAIControllerBase>(OwnerComp.GetOwner());
	TObjectPtr<AEnemyBase> enemy = Cast<AEnemyBase>(controller->GetPawn());
	TObjectPtr<UEnemyStateComponent> state = enemy->GetEnemyStateComponent();

	TObjectPtr<AActor> target = controller->GetTargetActor();

	// ��� : target�� �ڸ� ���� ����
	// ���� : target�� ���ֺ��� ����
	float dot = FVector::DotProduct(enemy->GetActorForwardVector(), target->GetActorForwardVector());

	// ���� �ڸ� ���� �ִ� ��� ������ ���� ����
	if (dot > 0)
	{
		state->SetActionMode();
		return true;
	}

	// ����ġ�� ���� ����, ���, ȸ�Ǹ� ���մϴ�.
	TArray<float> weights = Cast<UGameInstanceBase>(GetWorld()->GetGameInstance())->GetTacticalWeights_Of_EnemyType(enemy->GetEnemyType());
	int32 tacticsIndex = UsefulMath::WeightedRandomIndex(weights);

	switch (tacticsIndex)
	{
		case 0 :
			state->SetActionMode();
			break;
		case 1:
			state->SetDefendMode();
			break;
		case 2:
			state->SetEvadeMode();
			break;
	}


	return true;
}
