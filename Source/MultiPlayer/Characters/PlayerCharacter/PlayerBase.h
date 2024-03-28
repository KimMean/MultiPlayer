#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Definitions/PlayerDefinition.h"
#include "PlayerBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
//class UWidgetComponent;
class UGameUI;

class AWeaponBase;
class UInventoryComponent;

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

public :
	EPlayerClass GetPlayerClass();

public :
	virtual void SetVisibility(bool InVisibility) override;

public:
	/* Set whether combos are possible. */
	void SetComboEnable(bool InActivate);
	/* Increase Combo Count */
	void IncreaseComboCount();

protected :
	/* Attacks when you click the left mouse button. */
	virtual void OnAttack();
	/* Called when hit */
	virtual void OnHit() override;
public :
	/* This function is called by notify */
	virtual void ExtraAttack();

public :
	virtual void OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState) override;

	virtual void OnHealthPointChanged() override;

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

protected :	//Widget
	UPROPERTY(VisibleDefaultsOnly)
		TSubclassOf<UGameUI> GameWidgetClass;
	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<UGameUI> GameWidget;

	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<UInventoryComponent> Inventory;

	UPROPERTY(VisibleDefaultsOnly)
		EPlayerClass PlayerClass = EPlayerClass::None;

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
