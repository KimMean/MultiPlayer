#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/WeaponBase.h"
#include "SphereWeapon.generated.h"

UCLASS()
class MULTIPLAYER_API ASphereWeapon : public AWeaponBase
{
	GENERATED_BODY()

public :
	ASphereWeapon();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public :
	void SetCollisionRadius(float InRadius) override;
};
