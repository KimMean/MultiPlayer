#include "Notifies/NotifyState/CharacterInvincibility.h"

#include "Characters/CharacterBase.h"

UCharacterInvincibility::UCharacterInvincibility()
{

}

void UCharacterInvincibility::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;

	Character = Cast<ACharacterBase>(MeshComp->GetOwner());
	if (Character == nullptr) return;

	Character->SetInvincibility(true);
}

void UCharacterInvincibility::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
}

void UCharacterInvincibility::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;
	if (Character == nullptr) return;

	Character->SetInvincibility(false);
	Character = nullptr;
}
