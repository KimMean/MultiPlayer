#include "Notifies/Notify/LaunchCharacter.h"

#include "Characters/CharacterBase.h"

ULaunchCharacter::ULaunchCharacter()
{
}

void ULaunchCharacter::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;

	ACharacterBase* character = Cast<ACharacterBase>(MeshComp->GetOwner());
	if (character == nullptr) return;

	FVector velocity = character->GetActorForwardVector();
	velocity *= Velocity;
	velocity.Normalize();
	velocity *= Distance;
	character->LaunchCharacter(velocity, bXYOverride, bZOverride);
}
