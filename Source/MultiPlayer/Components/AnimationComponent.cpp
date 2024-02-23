#include "Components/AnimationComponent.h"

#include "Characters/CharacterBase.h"
#include "Datas/EnemyData/EnemyAnimationData.h"

UAnimationComponent::UAnimationComponent()
{

}


void UAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UAnimationComponent::PlayAnimMontage(ECharacterState InState)
{
	if (!AnimDatas) return;

	ACharacterBase* character = Cast<ACharacterBase>(GetOwner());

	//const TObjectPtr<FEnemyAnimData> data = AnimDatas->GetAnimationData(InState);

	//if (!data) return;

	character->PlayAnimMontage(AnimDatas->GetAnimationMontageData(InState));
}
