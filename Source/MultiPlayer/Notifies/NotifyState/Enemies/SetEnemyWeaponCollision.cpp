#include "Notifies/NotifyState/Enemies/SetEnemyWeaponCollision.h"

#include "Characters/Enemies/EnemyBase.h"
#include "Actors/Weapons/WeaponBase.h"

FString USetEnemyWeaponCollision::GetNotifyName_Implementation() const
{
	return "Collision Enable";
}

void USetEnemyWeaponCollision::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<AEnemyBase> enemy = Cast<AEnemyBase>(MeshComp->GetOwner());

	if(!enemy->IsEnemyHasWeaponOnTheType(Type)) return;

	enemy->GetEnemyWeaponOfWeaponType(Type)->SetCollisionEnabled(true);

}

void USetEnemyWeaponCollision::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (MeshComp->GetWorld()->WorldType == EWorldType::EditorPreview) return;

	TObjectPtr<AEnemyBase> enemy = Cast<AEnemyBase>(MeshComp->GetOwner());

	if (!enemy->IsEnemyHasWeaponOnTheType(Type)) return;

	enemy->GetEnemyWeaponOfWeaponType(Type)->SetCollisionEnabled(false);

}
