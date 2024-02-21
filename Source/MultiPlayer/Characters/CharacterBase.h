#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "CharacterInformation.h"
#include "Enums/AttackType.h"
#include "Enums/CharacterState.h"
#include "Enums/DirectionState.h"
#include "CharacterBase.generated.h"

class AWeaponBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterStateTypeChanged, ECharacterState, InPrevType, ECharacterState, InNewType);

UCLASS()
class MULTIPLAYER_API ACharacterBase : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FCharacterStatus OriginStatus;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FCharacterStatus CurStatus;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	ECharacterState CharacterState;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	EDirectionState HitDirection;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<AWeaponBase> Weapon;
  
	/* Generic Team Agent Interface */
	UPROPERTY(VisibleDefaultsOnly, Category = "AI")
		FGenericTeamId GenericTeamID;

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

	const ECharacterState GetCharacterState() const { return CharacterState; }
	const EDirectionState GetHitDirection() const { return HitDirection; }

	TObjectPtr<AWeaponBase> GetWeapon() { return Weapon; }
		
	const bool IsFalling() const { return GetCharacterMovement()->IsFalling(); }
	const bool IsSaveHit() { return bSaveHit; }

	void SetInvincibility(const bool Value) { bInvincibility = Value; }
	const bool& IsInvincibility() const { return bInvincibility; }

	void SetCharacterState(ECharacterState InState);

public :
	// ~Begin IGeneric Team Agent Interface
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;

	virtual FGenericTeamId GetGenericTeamId() const override;
	// ~End IGeneric Team Agent Interface
  
public :
	/* 
	* Character State Type Changed Delegate
	* ex) FuntionName(ECharacterState InPrevType, ECharacterState InNewType);
	*/
	UPROPERTY(BlueprintAssignable)
		FCharacterStateTypeChanged OnCharacterStateTypeChanged;
    
private:
	bool bInvincibility = false;
	bool bSaveHit = false;
};
