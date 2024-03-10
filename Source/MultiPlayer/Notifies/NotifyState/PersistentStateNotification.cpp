#include "Notifies/NotifyState/PersistentStateNotification.h"

#include "Characters/CharacterBase.h"

FString UPersistentStateNotification::GetNotifyName_Implementation() const
{
	return "Persistent State Notification";
}

void UPersistentStateNotification::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	character = Cast<ACharacterBase>(MeshComp->GetOwner());

	TickTimer = 0;
}

void UPersistentStateNotification::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TickTimer += FrameDeltaTime;
	if (TickTimer >= Interval)
	{
		TickTimer -= Interval;
		character->PersistentStatusNotification(CharacterState);
	}
}

void UPersistentStateNotification::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	character = nullptr;
}
