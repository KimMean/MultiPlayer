#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "EnemyBase.generated.h"

class AAIControllerBase;
class UBehaviorTree;
class UWidgetComponent;

UENUM()
enum class EEnemyClass : uint8
{
	None,
	Normal,
	Elite,
	Boss,
	MAX,
};

/*
* EnemyType
* Enemy types exist to help you choose your tactics when attacking.
*/
UENUM()
enum class EEnemyType : uint8
{
	None,
	Offensive,
	Defensive,
	Shooter,
	Support,
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

	virtual void Tick(float DeltaSeconds) override;

public:
	/* return Behavior Tree */
	UBehaviorTree* GetBehaviorTree();

public :
	/* return EnemyType */
	EEnemyType GetEnemyTacticsType();


protected:
	/* Set AIController Sight Radius */
	void SetSenseConfigSight_SightRadius(float InRadius);
	/* Set AIController Lose Sight Radius */
	void SetSenseConfigSight_LoseSightRadius(float InRadius);
	/* Set AIController Action Range */
	void SetActionRange(float InActionRange);

public :
	virtual void OnHealthPointChanged() override;

	virtual void OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState) override;

protected:
	/* AI Controller */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|AI|Controller")
		TSubclassOf<AAIControllerBase> AIController;

	/* Behavior Tree */
	UPROPERTY(EditDefaultsOnly, Category = "Enemy|AI|Behavior")
		TObjectPtr<UBehaviorTree> BehaviorTree;

	/* WidgetComponent*/
	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<UWidgetComponent> Widget;



protected:
	/* It must match the data table. */
	UPROPERTY(EditDefaultsOnly, Category = "Enemy|Property")
		FString EnemyName = "Unknown";

	/* Monster Class Type */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		EEnemyClass EnemyClassType;
	
	/* 몬스터의 전술 타입 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		EEnemyType EnemyTacticsType;

};
