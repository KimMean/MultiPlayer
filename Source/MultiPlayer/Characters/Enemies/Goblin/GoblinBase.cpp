#include "Characters/Enemies/Goblin/GoblinBase.h"

#include "Components/CapsuleComponent.h"

AGoblinBase::AGoblinBase()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(60);
	// Skeletal Mesh�� ������ �� �ִ� ��ũ��Ʈ �ϳ� �ۼ��ϸ� ����� ���ϵ� ��
	// Assets Data -> GetMesh("EnemyName?") ��������
	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"/Script/Engine.SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Gruntling/SK_Exodus_Gruntling.SK_Exodus_Gruntling'");
	GetMesh()->SetSkeletalMesh(mesh.Object);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -60));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));


}

void AGoblinBase::BeginPlay()
{
	Super::BeginPlay();
}
