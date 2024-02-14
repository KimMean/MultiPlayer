#include "Components/Enemy/EnemyAnimationComponent.h"

#include "Characters/CharacterBase.h"
#include "Datas/EnemyData/EnemyAnimationData.h"

UEnemyAnimationComponent::UEnemyAnimationComponent()
{
}


void UEnemyAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UEnemyAnimationComponent::PlayAnimation_Action()
{
	PlayAnimMontage(EEnemyStateType::Action);
}

void UEnemyAnimationComponent::PlayAnimMontage(EEnemyStateType InState)
{
	if (!AnimDatas) return;

	ACharacterBase* character = Cast<ACharacterBase>(GetOwner());

	//const TObjectPtr<FEnemyAnimData> data = AnimDatas->GetAnimationData(InState);

	//if (!data) return;

	character->PlayAnimMontage(AnimDatas->GetAnimationMontageData(InState));
}



