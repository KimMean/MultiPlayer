#include "Actors/Weapons/BoxWeapon.h"
#include "Components/BoxComponent.h"

#include "Utilities/DebugLog.h"

ABoxWeapon::ABoxWeapon()
{
	CollisionType = ECollisionType::Box;
	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	//RootComponent = Collision;

	//Mesh->SetupAttachment(RootComponent);
}

void ABoxWeapon::BeginPlay()
{
	Super::BeginPlay();

}

void ABoxWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
