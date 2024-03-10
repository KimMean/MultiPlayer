#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "Enums/AttackType.h"
#include "Enums/CharacterState.h"
#include "Enums/DirectionState.h"
#include "Enums/WeaponType.h"
#include "CharacterInformation.h"
#include "Components/StateComponent.h"
#include "Components/StatusComponent.h"
#include "CharacterBase.generated.h"

//class UStateComponent;
class UAnimationComponent;
class AWeaponBase;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterStateTypeChanged, ECharacterState, InPrevType, ECharacterState, InNewType);

UCLASS()
class MULTIPLAYER_API ACharacterBase : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;


/*
* Default Properties
* Get {}
* Set {}
*/
public:
	/* Character State Component */
	const TObjectPtr<UStateComponent> GetCharacterStateComponent() const;
	const TObjectPtr<UStatusComponent> GetCharacterStatusComponent() const;
		
	//void SetCharacterState(ECharacterState InState);

	/* return Animation Component */
	UAnimationComponent* GetAnimationComponent();

public :
	virtual float TakeDamage(float Damage, struct FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser) override;

public :
	// ~Begin IGeneric Team Agent Interface
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;

	virtual FGenericTeamId GetGenericTeamId() const override;
	// ~End IGeneric Team Agent Interface
  
public :
	UFUNCTION()
		virtual void OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState);
	/* HealthPoint Changed Delegate in UStatusComponent */
	virtual void OnHealthPointChanged();

public :
	/* Run with Animation Notify */
	virtual void StatusNotification(ECharacterState InCharacterState);

	/* Run with Animation Notify State */
	virtual void PersistentStatusNotification(ECharacterState InCharacterState);

	/* Called when hit */
	virtual void OnHit();

public:
	// Weapons
	void SetWeaponCollisionEnable(EWeaponType InWeaponType, bool InEnable);
	/* Check if you have a weapon matching your weapon type */
	bool IsCharacterHasWeaponOnTheType(EWeaponType InWeaponType);
	/* Get a weapon that matches your weapon type. */
	TObjectPtr<AWeaponBase> GetCharacterWeaponOfWeaponType(EWeaponType InWeaponType);

protected :
	virtual void AdjustHealthPoint(float InAdjustValue);

protected :
	/* Weapon */
	UPROPERTY(VisibleDefaultsOnly)
		TMap<EWeaponType, TObjectPtr<AWeaponBase>> Weapons;

protected:
	/* Character State Component */
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UStateComponent> CharacterState;
	/* Character Status Component */
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UStatusComponent> CharacterStatus;

	/* Animation Component */
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UAnimationComponent> Animation;

	/* Generic Team Agent Interface */
	UPROPERTY(VisibleDefaultsOnly, Category = "Character|TeamID")
		FGenericTeamId GenericTeamID;

};
