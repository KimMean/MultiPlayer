#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/WeaponBase.h"
#include "CapsuleWeapon.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API ACapsuleWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	ACapsuleWeapon();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
