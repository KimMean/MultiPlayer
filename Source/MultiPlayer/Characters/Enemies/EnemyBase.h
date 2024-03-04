#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "Actors/Weapons/WeaponBase.h"
#include "Enums/WeaponType.h"
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

	//~ Begin ACharacter Interface.
	virtual void PostInitializeComponents() override;
	//~ End ACharacter Interface.

protected :
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

public:
	/* return Behavior Tree */
	UBehaviorTree* GetBehaviorTree();

public :
	/* return EnemyType */
	EEnemyType GetEnemyTacticsType();


public :
	/* Check if you have a weapon matching your weapon type */
	bool IsEnemyHasWeaponOnTheType(EWeaponType InWeaponType);
	/* Get a weapon that matches your weapon type. */
	TObjectPtr<AWeaponBase> GetEnemyWeaponOfWeaponType(EWeaponType InWeaponType);

protected:
	/* Set AIController Sight Radius */
	void SetSenseConfigSight_SightRadius(float InRadius);
	/* Set AIController Lose Sight Radius */
	void SetSenseConfigSight_LoseSightRadius(float InRadius);
	/* Set AIController Action Range */
	void SetActionRange(float InActionRange);

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

	UPROPERTY(VisibleDefaultsOnly)
		TMap<EWeaponType, TObjectPtr<AWeaponBase>> Weapons;


protected :
	/* Monster Class Type */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		EEnemyClass EnemyClassType;
	
	/* ������ ���� Ÿ�� */
	UPROPERTY(VisibleDefaultsOnly, Category = "Enemy|Property")
		EEnemyType EnemyTacticsType;



};
