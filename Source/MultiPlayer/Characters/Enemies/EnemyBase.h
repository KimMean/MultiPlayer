#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "EnemyBase.generated.h"

class AAIControllerBase;
class UBehaviorTree;
class UEnemyAnimationComponent;

/*
* EnemyType
* Enemy types exist to help you choose your tactics when attacking.
*/
UENUM()
enum class EEnemyType : uint8
{
	NONE,
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

	//~ Begin ACharacter Interface.
	virtual void PostInitializeComponents() override;
	//~ End ACharacter Interface.

protected :
	virtual void BeginPlay() override;


public:
	/* return Behavior Tree */
	UBehaviorTree* GetBehaviorTree();



public :
	/* return EnemyType */
	EEnemyType GetEnemyType();


protected:
	/* AI Controller */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|AI|Controller")
		TSubclassOf<AAIControllerBase> AIController;

	/* Behavior Tree */
	UPROPERTY(EditDefaultsOnly, Category = "Enemy|AI|Behavior")
		TObjectPtr<UBehaviorTree> BehaviorTree;


protected :
	/* 몬스터의 전술 타입 */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		EEnemyType EnemyType;

};
