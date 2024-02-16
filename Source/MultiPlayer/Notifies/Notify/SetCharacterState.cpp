#include "Notifies/Notify/SetCharacterState.h"

#include "Characters/CharacterBase.h"

FString USetCharacterState::GetNotifyName_Implementation() const
{
	return "Set Character State";
}

void USetCharacterState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(MeshComp->GetOwner());
	character->SetCharacterState(StateType);
}
