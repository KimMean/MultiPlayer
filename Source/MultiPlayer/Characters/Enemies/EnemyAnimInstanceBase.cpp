#include "Characters/Enemies/EnemyAnimInstanceBase.h"

#include "KismetAnimationLibrary.h"

#include "Characters/Enemies/EnemyBase.h"

void UEnemyAnimInstanceBase::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerEnemy = Cast<AEnemyBase>(TryGetPawnOwner());
}

void UEnemyAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (OwnerEnemy == nullptr) return;

	Speed = OwnerEnemy->GetVelocity().Size2D();
	Direction = UKismetAnimationLibrary::CalculateDirection(OwnerEnemy->GetVelocity(), OwnerEnemy->GetActorRotation());
}
