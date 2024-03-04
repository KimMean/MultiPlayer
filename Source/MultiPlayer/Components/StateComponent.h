#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enums/CharacterState.h"
#include "StateComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCharacterStateChangeDelegate, ECharacterState, InPrevType, ECharacterState, InNewType);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYER_API UStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStateComponent();

protected:
	virtual void BeginPlay() override;

public :
	bool GetIsIdleMode();
	bool GetIsWaitMode();
	bool GetIsMoveMode();
	bool GetIsAttackMode();
	bool GetIsDefendMode();
	bool GetIsPatrolMode();
	bool GetIsChaseMode();
	bool GetIsHoldMode();
	bool GetIsHitMode();
	bool GetIsEvationMode();
	bool GetIsDeathMode();

public :
	void SetIdleMode();
	void SetWaitMode();
	void SetMoveMode();
	void SetAttackMode();
	void SetDefendMode();
	void SetPatrolMode();
	void SetChaseMode();
	void SetHoldMode();
	void SetHitMode();
	void SetEvationMode();
	void SetDeathMode();

public:
	const ECharacterState GetCharacterState();
	void SetCharacterState(ECharacterState InState);

private :
	bool CheckCharacterState(ECharacterState InState);


public :
	UPROPERTY(BlueprintAssignable)
		FCharacterStateChangeDelegate CharacterStateChangedDelegate;

private :
	UPROPERTY(VisibleAnywhere)
		ECharacterState CharacterState;
};
