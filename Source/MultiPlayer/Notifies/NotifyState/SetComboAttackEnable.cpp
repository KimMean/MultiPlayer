#include "Notifies/NotifyState/SetComboAttackEnable.h"

#include "Characters/PlayerCharacter/PlayerBase.h"

FString USetComboAttackEnable::GetNotifyName_Implementation() const
{
	return "SetComboEnable";
}

void USetComboAttackEnable::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<APlayerBase> player = Cast<APlayerBase>(MeshComp->GetOwner());
	player->SetComboEnable(true);
}

void USetComboAttackEnable::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<APlayerBase> player = Cast<APlayerBase>(MeshComp->GetOwner());
	player->SetComboEnable(false);
}
