#include "Notifies/Notify/StateNotification.h"

#include "Characters/CharacterBase.h"

FString UStateNotification::GetNotifyName_Implementation() const
{
	return "State Notification";
}

void UStateNotification::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(MeshComp->GetOwner());

	character->StatusNotification(CharacterState);
}
