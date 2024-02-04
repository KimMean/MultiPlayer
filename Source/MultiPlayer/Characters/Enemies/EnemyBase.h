#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "EnemyBase.generated.h"

UCLASS()
class MULTIPLAYER_API AEnemyBase : public ACharacterBase
{
	GENERATED_BODY()
	
public :
	AEnemyBase();

protected :
	virtual void BeginPlay() override;

private :
	/* 몬스터의 레벨 */
	UPROPERTY(VisibleDefaultsOnly)
		uint8 Level;

	/* 몬스터의 이름 */
	UPROPERTY(VisibleDefaultsOnly)
		FString Name;

	/* 몬스터가 주는 경험치 */
	UPROPERTY(VisibleDefaultsOnly)
		int32 Experience;

	/* 몬스터 체력 */
	UPROPERTY(VisibleDefaultsOnly)
		float HealthPoint;

	/* 몬스터 물리 공격력 */
	UPROPERTY(VisibleDefaultsOnly)
		int32 AttackPower;

	/* 몬스터 마법 공격력 */
	UPROPERTY(VisibleDefaultsOnly)
		int32 MagicPower;

	/* 몬스터 물리 저항력 */
	UPROPERTY(VisibleDefaultsOnly)
		int32 PhysicalResistance;

	/* 몬스터 마법 저항력 */
	UPROPERTY(VisibleDefaultsOnly)
		int32 MagicResistance;


};
