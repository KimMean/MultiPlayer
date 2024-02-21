#include "Actors/Weapons/SphereWeapon.h"

#include "Components/SphereComponent.h"

ASphereWeapon::ASphereWeapon()
{
	Collision = CreateDefaultSubobject<USphereComponent>("Collision");
	RootComponent = Collision;

	Mesh->SetupAttachment(RootComponent);
}

void ASphereWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ASphereWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASphereWeapon::SetCollisionRadius(float InRadius)
{
	// �Ź� ĳ���� �ؾ��ϴµ� ĳ������ ���� �ʴ� ����� ������?
	// �� �� �����ϰ� ����� ������ Collision->Get()�� ���� �� �ڵ����� ĳ���� �Ǿ ��ȯ�Ǵ� ������ ������?
	Cast<USphereComponent>(Collision)->SetSphereRadius(InRadius);
}


