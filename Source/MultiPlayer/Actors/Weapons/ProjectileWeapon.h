#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/SphereWeapon.h"
#include "ProjectileWeapon.generated.h"

UCLASS()
class MULTIPLAYER_API AProjectileWeapon : public ASphereWeapon
{
	GENERATED_BODY()
	
public :
	AProjectileWeapon();

protected:
	virtual void BeginPlay() override;

};
