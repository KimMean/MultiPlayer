#include "Actors/Weapons/SphereWeapon.h"

#include "Components/SphereComponent.h"

ASphereWeapon::ASphereWeapon()
{
	CollisionType = ECollisionType::Sphere;
	Collision = CreateDefaultSubobject<USphereComponent>("Collision");

	Collision->SetupAttachment(RootComponent);
	//RootComponent = Collision;

	//Mesh->SetupAttachment(RootComponent);
}

void ASphereWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ASphereWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


