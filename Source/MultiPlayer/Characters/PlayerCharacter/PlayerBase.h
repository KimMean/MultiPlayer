#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "PlayerBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

class AWeaponBase;

struct FInputActionInstance;

//USTRUCT(BlueprintType)
//struct FSkillInformation
//{
//	GENERATED_BODY()
//
//protected:
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//	UFunction Test;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//	TWeakPtr<UAnimMontage> SkillAnim;
//};

UCLASS()
class MULTIPLAYER_API APlayerBase : public ACharacterBase
{
	GENERATED_BODY()

private:
	/* Warrior */
	const int MAX_ATTACK_COMBO = 3;

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Component")
	TObjectPtr<USpringArmComponent> SpringArm = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Component")
	TObjectPtr<UCameraComponent> Camera = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	TObjectPtr<AWeaponBase> Weapon = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	TMap<FString, TObjectPtr<UInputAction>> InputActions;

	//UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	//TArray<TWeakPtr<UAnimMontage>> SkillAnims;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	TEnumAsByte<EDirectionState> MoveDirection;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	float VerticalLookRate = 10.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	float HorizontalLookRate = 10.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	float EvationCoolTime = 0.0f;

public:
	APlayerBase();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	virtual void ResetState() override;
	virtual void ResetHitState() override;

	virtual const bool GetDamage(const int32 Damage, const EAttackType Type, const FVector OtherLocation, const FHitResult& SweepResult);

	void ResetEvation();
	const bool& IsEvation() const { return bEvation; }
	const bool& IsMoveable() const { return bMoveable; }
	const bool& IsAttacking() const { return bAttacking; }
	const bool& IsSmashing() const { return bSmashing; }

	const int& GetAttackCombo() const { return AttackCombo; }

	const bool SaveAttack();
	void ResetAttackState();

	/**
	* Get Move Direction
	*/
	const EDirectionState GetDirection() const { return MoveDirection.GetValue(); }

private:
	void OnForwardMove(const FInputActionInstance& Instance);
	void OnRightMove(const FInputActionInstance& Instance);

	void EndForwardMove(const FInputActionInstance& Instance);
	void EndRightMove(const FInputActionInstance& Instance);

	void VerticalLook(const FInputActionInstance& Instance);
	void HorizontalLook(const FInputActionInstance& Instance);

	void OnLeftClick(const FInputActionInstance& Instance);
	void OnRightClick(const FInputActionInstance& Instance);

	void OnEvation(const FInputActionInstance& Instance);

protected:
	virtual void OnAttacking();
	virtual void OnSmashing();

private:
	bool bEvation = false;
	bool bMoveable = true;
	bool bCanAttack = true;
	bool bAttacking = false;
	bool bSmashing = false;
	bool bSaveAttack = false;
	bool bSaveSmash = false;

	int AttackCombo = 0;
};
