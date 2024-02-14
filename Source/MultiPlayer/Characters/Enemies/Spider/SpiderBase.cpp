#include "Characters/Enemies/Spider/SpiderBase.h"

#include "Components/CapsuleComponent.h"

ASpiderBase::ASpiderBase()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(60);
	GetCapsuleComponent()->SetCapsuleRadius(60);

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"/Script/Engine.SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Spiderling/SK_Spiderling.SK_Spiderling'");
	GetMesh()->SetSkeletalMesh(mesh.Object);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -60));
}

void ASpiderBase::BeginPlay()
{
	Super::BeginPlay();
}
