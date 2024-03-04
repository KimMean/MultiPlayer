#include "Actors/Weapons/ProjectileWeapon.h"

#include "GameFramework/ProjectileMovementComponent.h"

AProjectileWeapon::AProjectileWeapon()
{
	Projectile = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovement");
}

void AProjectileWeapon::BeginPlay()
{
	Super::BeginPlay();
}
