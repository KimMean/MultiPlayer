#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
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
	FORCEINLINE UBehaviorTree* GetBehaviorTree() { return BehaviorTree; }
	//FORCEINLINE uint8 GetTeamID() { return TeamID; }

protected:
	/* AI Controller */
	UPROPERTY(VisibleDefaultsOnly, Category = "EnemyBase|AI|Controller")
		TSubclassOf<AAIControllerBase> AIController;

	/* Behavior Tree */
	UPROPERTY(EditDefaultsOnly, Category = "EnemyBase|AI|Behavior")
		TObjectPtr<UBehaviorTree> BehaviorTree;

protected :
	/* ������ ���� */
	UPROPERTY(VisibleDefaultsOnly)
		uint8 Level;

	/* ������ �̸� */
	UPROPERTY(VisibleDefaultsOnly)
		FString Name;

	/* ���Ͱ� �ִ� ����ġ */
	UPROPERTY(VisibleDefaultsOnly)
		int32 Experience;

	/* ���� ü�� */
	UPROPERTY(VisibleDefaultsOnly)
		float HealthPoint;

	/* ���� ���� ���ݷ� */
	UPROPERTY(VisibleDefaultsOnly)
		int32 AttackPower;

	/* ���� ���� ���ݷ� */
	UPROPERTY(VisibleDefaultsOnly)
		int32 MagicPower;

	/* ���� ���� ���׷� */
	UPROPERTY(VisibleDefaultsOnly)
		int32 PhysicalResistance;

	/* ���� ���� ���׷� */
	UPROPERTY(VisibleDefaultsOnly)
		int32 MagicResistance;


};
