#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Components/Enemy/EnemyStateComponent.h"
#include "EnemyBase.generated.h"

class AAIControllerBase;
class UBehaviorTree;

UCLASS()
class MULTIPLAYER_API AEnemyBase : public ACharacterBase
{
	GENERATED_BODY()
	
public :
	AEnemyBase();

protected :
	virtual void BeginPlay() override;


public:
	/* Behavior Tree */
	FORCEINLINE UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }

public :
	/* Enemy State Component, EnemyStateTypeChanged Delegate */
	UFUNCTION()
		virtual void OnEnemyStateChanged(EEnemyStateType InPrevType, EEnemyStateType InNewType);

protected:
	/* AI Controller */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|AI|Controller")
		TSubclassOf<AAIControllerBase> AIController;

	/* Behavior Tree */
	UPROPERTY(EditDefaultsOnly, Category = "Enemy|AI|Behavior")
		TObjectPtr<UBehaviorTree> BehaviorTree;

protected :
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|State")
		TObjectPtr<UEnemyStateComponent> State;

protected :
	/* ������ ���� */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		uint8 Level;

	/* ������ �̸� */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		FString Name;

	/* ���Ͱ� �ִ� ����ġ (����) */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 Experience;

	/* ���� ü�� */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		float HealthPoint;

	/* ���� ���� ���ݷ� */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 AttackPower;

	/* ���� ���� ���ݷ� */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 MagicPower;

	/* ���� ���� ���׷� */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 PhysicalResistance;

	/* ���� ���� ���׷� */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 MagicResistance;

};
