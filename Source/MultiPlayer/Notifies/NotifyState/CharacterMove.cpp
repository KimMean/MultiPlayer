#include "Notifies/NotifyState/CharacterMove.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Characters/CharacterBase.h"

UCharacterMove::UCharacterMove()
{
}

void UCharacterMove::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;

	Character = Cast<ACharacterBase>(MeshComp->GetOwner());
	if (Character == nullptr) return;

	if (bDirectionConservation == true)
		MoveDirection = Character->GetVelocity();
	else
		MoveDirection = Character->GetActorForwardVector() * Direction;

	//if(bSpeedConservation == true)
	//	Speed = Character->GetCharacterMovement()->MaxWalkSpeed;

	Character->GetCharacterMovement()->MaxWalkSpeed += IncreaseSpeed;
}

void UCharacterMove::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;
	if (Character == nullptr) return;

	MoveDirection.Normalize();
	Character->AddMovementInput(MoveDirection);
}

void UCharacterMove::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;
	if (Character == nullptr) return;

	Character->GetCharacterMovement()->MaxWalkSpeed -= IncreaseSpeed;
	Character = nullptr;
}
