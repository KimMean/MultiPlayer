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
