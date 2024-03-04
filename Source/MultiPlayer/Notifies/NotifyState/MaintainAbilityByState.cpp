#include "Notifies/NotifyState/MaintainAbilityByState.h"

#include "Characters/CharacterBase.h"

FString UMaintainAbilityByState::GetNotifyName_Implementation() const
{
	return "Maintain Ability";
}

void UMaintainAbilityByState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	character = Cast<ACharacterBase>(MeshComp->GetOwner());

	TickTimer = 0;
}

void UMaintainAbilityByState::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TickTimer += FrameDeltaTime;
	if (TickTimer >= Interval)
	{
		TickTimer -= Interval;
		character->MaintainAbility(CharacterState);
	}
}

void UMaintainAbilityByState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	character = nullptr;
	//character->AbilityActivation(CharacterState);
}
