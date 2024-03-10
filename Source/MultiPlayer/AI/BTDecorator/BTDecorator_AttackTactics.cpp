#include "AI/BTDecorator/BTDecorator_AttackTactics.h"

#include "MultiPlayerGameMode.h"
#include "GameSetting/Controllers/AIControllerBase.h"
#include "Characters/Enemies/EnemyBase.h"
#include "Characters/CharacterBase.h"
#include "Components/StateComponent.h"

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
	//TObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(controller->GetPawn());

	TObjectPtr<AActor> target = controller->GetTargetActor();

	// 양수 : target이 뒤를 보고 있음
	// 음수 : target과 마주보고 있음
	float dot = FVector::DotProduct(enemy->GetActorForwardVector(), target->GetActorForwardVector());

	// 적이 뒤를 보고 있는 경우 무조건 공격 모드로
	if (dot > 0)
	{
		enemy->GetCharacterStateComponent()->SetAttackMode();
		return true;
	}

	// 가중치에 따라 공격, 방어, 회피를 정합니다.
	TArray<float> weights = Cast<AMultiPlayerGameMode>(GetWorld()->GetAuthGameMode())->GetTacticalWeights_Of_EnemyType(enemy->GetEnemyTacticsType());
	//TArray<float> weights = Cast<UGameInstanceBase>(GetWorld()->GetGameInstance())->GetTacticalWeights_Of_EnemyType(enemy->GetEnemyTacticsType());
	int32 tacticsIndex = UsefulMath::WeightedRandomIndex(weights);

	switch (tacticsIndex)
	{
		case 0 :
			enemy->GetCharacterStateComponent()->SetAttackMode();
			break;
		case 1:
			enemy->GetCharacterStateComponent()->SetDefendMode();
			break;
		case 2:
			enemy->GetCharacterStateComponent()->SetEvationMode();
			break;
	}


	return true;
}
