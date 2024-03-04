#include "Notifies/Notify/AbilityActivationByState.h"

#include "Characters/CharacterBase.h"

FString UAbilityActivationByState::GetNotifyName_Implementation() const
{
	return "Ability Activation";
}

void UAbilityActivationByState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(MeshComp->GetOwner());

	character->AbilityActivation(CharacterState);
	//character->GetCharacterStateComponent()->SetCharacterState(CharacterState);
}
