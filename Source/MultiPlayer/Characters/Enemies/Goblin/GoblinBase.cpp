#include "Characters/Enemies/Goblin/GoblinBase.h"

#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"

AGoblinBase::AGoblinBase()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(60);
	// Skeletal Mesh를 가져올 수 있는 스크립트 하나 작성하면 깔끔해 보일듯 함
	// Assets Data -> GetMesh("EnemyName?") 느낌으로
	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"/Script/Engine.SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Gruntling_Guardian/SK_Gruntling_Guardian.SK_Gruntling_Guardian'");
	GetMesh()->SetSkeletalMesh(mesh.Object);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -60));
}

void AGoblinBase::BeginPlay()
{
	Super::BeginPlay();
}
