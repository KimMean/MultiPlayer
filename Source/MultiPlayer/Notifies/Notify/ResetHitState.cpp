#include "Notifies/Notify/ResetHitState.h"

#include "Characters/CharacterBase.h"

UResetHitState::UResetHitState()
{

}

void UResetHitState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;

	ACharacterBase* character = Cast<ACharacterBase>(MeshComp->GetOwner());
	if (character == nullptr) return;

	character->ResetHitState();
}
