#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CharacterInformation.h"
#include "Enums/AttackType.h"
#include "Enums/CharacterState.h"
#include "Enums/DirectionState.h"
#include "CharacterBase.generated.h"

class ABoxWeapon;

UCLASS()
class MULTIPLAYER_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FCharacterStatus OriginStatus;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FCharacterStatus CurStatus;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TEnumAsByte<ECharacterState> CharacterState;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TEnumAsByte<EDirectionState> HitDirection;

	//UPROPERTY(BlueprintReadOnly, EditAnywhere)
	//TSoftObjectPtr<AWeaponBase> Weapon;

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

public:
	void StopMove();
	void ResumeMove();

public:
	virtual void ResetState();
	virtual void ResetHitState();
	
	virtual const bool GetDamage(const int32 Damage, const EAttackType Type, const FVector OtherLocation, const FHitResult& SweepResult);

	const FCharacterStatus& GetStatus() const { return CurStatus; }

	const ECharacterState GetCharacterState() const { return CharacterState.GetValue(); }
	const EDirectionState GetHitDirection() const { return HitDirection.GetValue(); }
		
	const bool IsFalling() const { return GetCharacterMovement()->IsFalling(); }
	const bool IsSaveHit() { return bSaveHit; }

	void SetInvincibility(const bool Value) { bInvincibility = Value; }
	const bool& IsInvincibility() const { return bInvincibility; }

private:
	/* ¹«Àû */
	bool bInvincibility = false;
	bool bSaveHit = false;
};
