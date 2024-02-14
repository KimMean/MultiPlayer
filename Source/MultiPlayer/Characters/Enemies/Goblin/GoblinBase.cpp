#include "Characters/Enemies/Goblin/GoblinBase.h"

#include "Components/CapsuleComponent.h"
#include "Components/BoxComponent.h"

AGoblinBase::AGoblinBase()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(60);
	// Skeletal Mesh�� ������ �� �ִ� ��ũ��Ʈ �ϳ� �ۼ��ϸ� ����� ���ϵ� ��
	// Assets Data -> GetMesh("EnemyName?") ��������
	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"/Script/Engine.SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Gruntling_Guardian/SK_Gruntling_Guardian.SK_Gruntling_Guardian'");
	GetMesh()->SetSkeletalMesh(mesh.Object);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -60));
}

void AGoblinBase::BeginPlay()
{
	Super::BeginPlay();
}
