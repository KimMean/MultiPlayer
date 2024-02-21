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
	// 매번 캐스팅 해야하는데 캐스팅을 하지 않는 방법은 없을까?
	// 좀 더 간단하게 만들고 싶은데 Collision->Get()을 했을 때 자동으로 캐스팅 되어서 반환되는 문법이 있을까?
	Cast<USphereComponent>(Collision)->SetSphereRadius(InRadius);
}


