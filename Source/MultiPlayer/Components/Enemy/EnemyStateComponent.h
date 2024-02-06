#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyStateComponent.generated.h"


UENUM(BlueprintType)
enum class EEnemyStateType : uint8
{
	Idle,
	Patrol,
	Wait,
	Action,
	Chase,
	Retreat,
	Defend,
	Avoid,
	Hitted,
	Death,
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FEnemyStateTypeChanged, EEnemyStateType, InPrevType, EEnemyStateType, InNewType);


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYER_API UEnemyStateComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEnemyStateComponent();

protected:
	virtual void BeginPlay() override;

public:	
	//virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	FORCEINLINE bool IsIdleMode() { return Type == EEnemyStateType::Idle; }
	FORCEINLINE bool IsPatrolMode() { return Type == EEnemyStateType::Patrol; }
	FORCEINLINE bool IsWaitMode() { return Type == EEnemyStateType::Wait; }
	FORCEINLINE bool IsActionMode() { return Type == EEnemyStateType::Action; }
	FORCEINLINE bool IsChaseMode() { return Type == EEnemyStateType::Chase; }
	FORCEINLINE bool IsRetreatMode() { return Type == EEnemyStateType::Retreat; }
	FORCEINLINE bool IsDefendMode() { return Type == EEnemyStateType::Defend; }
	FORCEINLINE bool IsAvoidMode() { return Type == EEnemyStateType::Avoid; }
	FORCEINLINE bool IsHittedMode() { return Type == EEnemyStateType::Hitted; }
	FORCEINLINE bool IsDeathMode() { return Type == EEnemyStateType::Death; }

public:
	void SetIdleMode();
	void SetPatrolMode();
	void SetWaitMode();
	void SetActionMode();
	void SetChaseMode();
	void SetRetreatMode();
	void SetDefendMode();
	void SetAvoidMode();
	void SetHittedMode();
	void SetDeathMode();

private:
	void ChangeType(EEnemyStateType InType);

public:
	UPROPERTY(BlueprintAssignable)
		FEnemyStateTypeChanged OnEnemyStateTypeChanged;

private:
	EEnemyStateType Type;
};
