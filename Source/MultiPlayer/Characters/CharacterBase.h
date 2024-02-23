#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "Enums/AttackType.h"
#include "Enums/CharacterState.h"
#include "Enums/DirectionState.h"
#include "CharacterInformation.h"
#include "CharacterBase.generated.h"

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

public:
	const ECharacterState GetCharacterState() const { return CharacterState; }
		
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

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		ECharacterState CharacterState;

	/* Generic Team Agent Interface */
	UPROPERTY(VisibleDefaultsOnly, Category = "AI")
		FGenericTeamId GenericTeamID;
};
