#include "Notifies/NotifyState/SaveAttack.h"

#include "Characters/PlayerCharacter/PlayerBase.h"

USaveAttack::USaveAttack()
{

}

void USaveAttack::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;

	Character = Cast<APlayerBase>(MeshComp->GetOwner());
	if (Character == nullptr) return;

	bComboCheck = false;
}

void USaveAttack::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;
	if (Character == nullptr) return;

	if (bComboCheck == false)
		bComboCheck = Character->SaveAttack();
}

void USaveAttack::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetOwner() == nullptr) return;
	
	Character = nullptr;
}
