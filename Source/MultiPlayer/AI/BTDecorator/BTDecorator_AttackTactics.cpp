#include "AI/BTDecorator/BTDecorator_AttackTactics.h"

#include "GameSetting/GameInstance/GameInstanceBase.h"
#include "GameSetting/Controllers/AIControllerBase.h"
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

	TObjectPtr<AActor> target = controller->GetTargetActor();

	// ��� : target�� �ڸ� ���� ����
	// ���� : target�� ���ֺ��� ����
	float dot = FVector::DotProduct(enemy->GetActorForwardVector(), target->GetActorForwardVector());

	// ���� �ڸ� ���� �ִ� ��� ������ ���� ����
	if (dot > 0)
	{
		enemy->SetCharacterState(ECharacterState::Attack);
		return true;
	}

	// ����ġ�� ���� ����, ���, ȸ�Ǹ� ���մϴ�.
	TArray<float> weights = Cast<UGameInstanceBase>(GetWorld()->GetGameInstance())->GetTacticalWeights_Of_EnemyType(enemy->GetEnemyType());
	int32 tacticsIndex = UsefulMath::WeightedRandomIndex(weights);

	switch (tacticsIndex)
	{
		case 0 :
			enemy->SetCharacterState(ECharacterState::Attack);
			break;
		case 1:
			enemy->SetCharacterState(ECharacterState::Defend);
			break;
		case 2:
			enemy->SetCharacterState(ECharacterState::Evation);
			break;
	}


	return true;
}
