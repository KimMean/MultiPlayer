#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Components/Enemy/EnemyStateComponent.h"
#include "EnemyBase.generated.h"

class AAIControllerBase;
class UBehaviorTree;
class UEnemyAnimationComponent;

UENUM()
enum class EEnemyType : uint8
{
	NONE,
	Melee,
	Ranger,
	MAX,
};


UCLASS()
class MULTIPLAYER_API AEnemyBase : public ACharacterBase
{
	GENERATED_BODY()
	
public :
	AEnemyBase();

protected :
	virtual void BeginPlay() override;


public:
	/* return Behavior Tree */
	UBehaviorTree* GetBehaviorTree();
	/* return Enemy State Component */
	UEnemyStateComponent* GetEnemyStateComponent();
	/* return Enemy Animation Component */
	UEnemyAnimationComponent* GetEnemyAnimationComponent();


public :
	/* Enemy State Component, EnemyStateTypeChanged Delegate */
	UFUNCTION()
		virtual void OnEnemyStateChanged(EEnemyStateType InPrevType, EEnemyStateType InNewType);

public :
	EEnemyType GetEnemyType();



protected:
	/* AI Controller */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|AI|Controller")
		TSubclassOf<AAIControllerBase> AIController;

	/* Behavior Tree */
	UPROPERTY(EditDefaultsOnly, Category = "Enemy|AI|Behavior")
		TObjectPtr<UBehaviorTree> BehaviorTree;

protected :
	/* Enemy StateComponent */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|State")
		TObjectPtr<UEnemyStateComponent> State;

	/* Enemy StateComponent */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|State")
		TObjectPtr<UEnemyAnimationComponent> Animation;

protected :
	/* 몬스터의 전술 타입 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		EEnemyType EnemyType;

	/* 몬스터의 레벨 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		uint8 Level;

	/* 몬스터의 이름 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		FString Name;

	/* 몬스터가 주는 경험치 (무시) */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 Experience;

	/* 몬스터 체력 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		float HealthPoint;

	/* 몬스터 물리 공격력 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 AttackPower;

	/* 몬스터 마법 공격력 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 MagicPower;

	/* 몬스터 물리 저항력 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 PhysicalResistance;

	/* 몬스터 마법 저항력 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		int32 MagicResistance;

};
