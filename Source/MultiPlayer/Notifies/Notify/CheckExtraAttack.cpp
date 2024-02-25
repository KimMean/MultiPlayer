#include "Notifies/Notify/CheckExtraAttack.h"

#include "Characters/PlayerCharacter/PlayerBase.h"

FString UCheckExtraAttack::GetNotifyName_Implementation() const
{
	return "ExtraAttack";
}

void UCheckExtraAttack::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<APlayerBase> Player = Cast<APlayerBase>(MeshComp->GetOwner());
	Player->ExtraAttack();
}
