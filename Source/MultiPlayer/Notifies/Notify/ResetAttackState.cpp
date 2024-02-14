#include "Notifies/Notify/ResetAttackState.h"

#include "Characters/PlayerCharacter/PlayerBase.h"

UResetAttackState::UResetAttackState()
{
}

void UResetAttackState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;

	APlayerBase* character = Cast<APlayerBase>(MeshComp->GetOwner());
	if (character == nullptr) return;

	character->ResetAttackState();
}
