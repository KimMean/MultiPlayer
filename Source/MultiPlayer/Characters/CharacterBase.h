#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "Enums/AttackType.h"
#include "Enums/CharacterState.h"
#include "Enums/DirectionState.h"
#include "CharacterInformation.h"
#include "Components/StateComponent.h"
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
		
	//void SetCharacterState(ECharacterState InState);

	/* return Animation Component */
	UAnimationComponent* GetAnimationComponent();

public :
	// ~Begin IGeneric Team Agent Interface
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;

	virtual FGenericTeamId GetGenericTeamId() const override;
	// ~End IGeneric Team Agent Interface
  
public :
	UFUNCTION()
		virtual void OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState);

protected:
	/* Character State Component */
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UStateComponent> CharacterState;

	/* Animation Component */
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UAnimationComponent> Animation;

	/* Generic Team Agent Interface */
	UPROPERTY(VisibleDefaultsOnly, Category = "Character|TeamID")
		FGenericTeamId GenericTeamID;
};
