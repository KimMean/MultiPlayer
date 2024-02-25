#include "Components/AnimationComponent.h"

#include "Characters/CharacterBase.h"
#include "Datas/AnimationDataAssets.h"

UAnimationComponent::UAnimationComponent()
{

}


void UAnimationComponent::BeginPlay()
{
	Super::BeginPlay();

	
}

void UAnimationComponent::PlayAnimMontage(ECharacterState InState)
{
	//if (!AnimDatas) return;

	//ACharacterBase* character = Cast<ACharacterBase>(GetOwner());

	//const TObjectPtr<FEnemyAnimData> data = AnimDatas->GetAnimationData(InState);

	//if (!data) return;

	//character->PlayAnimMontage(AnimDatas->GetAnimationMontageData(InState));

	PlayAnimMontageByIndex(InState, 0);
}

void UAnimationComponent::PlayAnimMontageByIndex(ECharacterState InState, int InIndex)
{
	//if (!AnimDatas) return;

	//ACharacterBase* character = Cast<ACharacterBase>(GetOwner());

	//character->PlayAnimMontage(AnimDatas->GetAnimationMontageData(InState, InIndex));

	PlayAnimMontage(AnimDatas->GetAnimationMontageData(InState, InIndex));
}

void UAnimationComponent::PlayAnimMontageByRandom(ECharacterState InState)
{
	PlayAnimMontage(AnimDatas->GetAnimationMontageRandomData(InState));
}

void UAnimationComponent::PlayAnimMontage(TObjectPtr<UAnimMontage> InMontage)
{
	ACharacterBase* character = Cast<ACharacterBase>(GetOwner());
	character->PlayAnimMontage(InMontage);
}
