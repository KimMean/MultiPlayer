#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/WeaponBase.h"
#include "BoxWeapon.generated.h"

/**
 * 
 */
class UBoxComponent;

UCLASS()
class MULTIPLAYER_API ABoxWeapon : public AWeaponBase
{
	GENERATED_BODY()

public:
	ABoxWeapon();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

};
