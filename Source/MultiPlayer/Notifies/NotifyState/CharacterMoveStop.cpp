#include "Notifies/NotifyState/CharacterMoveStop.h"

#include "Characters/CharacterBase.h"

UCharacterMoveStop::UCharacterMoveStop()
{
}

void UCharacterMoveStop::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;

	Character = Cast<ACharacterBase>(MeshComp->GetOwner());
	if (Character == nullptr) return;

	Character->StopMove();
}

void UCharacterMoveStop::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	//Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	//if (MeshComp->GetOwner() == nullptr) return;
	//if (Character == nullptr) return;

	//Character->StopMove();
}

void UCharacterMoveStop::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;
	if (Character == nullptr) return;

	//Character->StopMove();
	Character->ResumeMove();
	Character = nullptr;
}
