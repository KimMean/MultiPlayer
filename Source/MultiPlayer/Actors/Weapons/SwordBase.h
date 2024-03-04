#pragma once

#include "CoreMinimal.h"
#include "Actors/Weapons/WeaponBase.h"
#include "SwordBase.generated.h"

UCLASS()
class MULTIPLAYER_API ASwordBase : public AWeaponBase
{
	GENERATED_BODY()

public :
	ASwordBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
};
