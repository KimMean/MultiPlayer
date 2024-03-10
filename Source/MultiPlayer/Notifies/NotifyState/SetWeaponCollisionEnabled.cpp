#include "Notifies/NotifyState/SetWeaponCollisionEnabled.h"

#include "Characters/CharacterBase.h"
#include "Actors/Weapons/WeaponBase.h"

FString USetWeaponCollisionEnabled::GetNotifyName_Implementation() const
{
	return "Set Collision";
}

void USetWeaponCollisionEnabled::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(MeshComp->GetOwner());
	character->SetWeaponCollisionEnable(WeaponType, true);
}

void USetWeaponCollisionEnabled::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<ACharacterBase> character = Cast<ACharacterBase>(MeshComp->GetOwner());
	character->SetWeaponCollisionEnable(WeaponType, false);
}
