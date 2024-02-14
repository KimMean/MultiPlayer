#include "Actors/Weapons/CapsuleWeapon.h"
#include "Components/CapsuleComponent.h"

ACapsuleWeapon::ACapsuleWeapon()
{
	//Collision = CreateDefaultSubobject<UCapsuleComponent>("Collision");
	//RootComponent = Collision;
	//
	//Mesh->SetupAttachment(RootComponent);
}

void ACapsuleWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ACapsuleWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
