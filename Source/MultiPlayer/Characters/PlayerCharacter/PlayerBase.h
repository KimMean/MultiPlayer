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

UCLASS()
class MULTIPLAYER_API APlayerBase : public ACharacterBase
{
	GENERATED_BODY()



public:
	APlayerBase();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected :
	/* Character movement W, S, A, D */
	void OnMove(const FInputActionInstance& Instance);

	/* Look based on mouse position */
	void OnLook(const FInputActionInstance& Instance);

	/* Left Mouse Button On Click */
	void OnAttack_LMB(const FInputActionInstance& Instance);
	/* Right Mouse Button On Click */
	void OnAttack_RMB(const FInputActionInstance& Instance);


public:
	/* Set whether combos are possible. */
	void SetComboEnable(bool InActivate);
	/* Increase Combo Count */
	void IncreaseComboCount();

protected :
	/* Attacks when you click the left mouse button. */
	virtual void OnAttack();

public :
	/* This function is called by notify */
	virtual void ExtraAttack();

public :
	virtual void OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState) override;

protected:
	/* Spring Arm Component */
	UPROPERTY(EditAnywhere, Category = "Player|Component")
		TObjectPtr<USpringArmComponent> SpringArm = nullptr;

	/* Camera Component */
	UPROPERTY(EditAnywhere, Category = "Player|Component")
		TObjectPtr<UCameraComponent> Camera = nullptr;

protected :
	/* Player Input Mapping Context */
	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputMappingContext> InputMapping;

	/* Player Input Action */
	UPROPERTY(EditAnywhere, Category = "Input")
		TMap<FString, TObjectPtr<UInputAction>> InputActions;


protected:
	/* Player Can Move? */
	bool bMoveable;

	/* This changes in notify when there is a combo attack. */
	bool bComboEnable;
	/* When continuous attacks are possible, it is changed when giving an attack command. */
	bool bComboAttack;
	/* Increases during combo attacks. */
	int32 ComboCount;
};
