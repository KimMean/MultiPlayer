#pragma once

#include "CoreMinimal.h"
#include "CharacterInformation.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStatus : public FTableRowBase
{
	GENERATED_BODY()

public:
	/* �г��� */
	UPROPERTY(VisibleAnywhere)
	FString CharacterName = "Character";

	/* ���� */
	UPROPERTY(VisibleAnywhere)
	int32 Level = 1;

	/* ����ġ */
	UPROPERTY(VisibleAnywhere)
	float Experience = 0;

	/* ü�� */
	UPROPERTY(VisibleAnywhere)
	int32 HealthPoint = 1;

	/* ���� */
	UPROPERTY(VisibleAnywhere)
	int32 MagicPoint = 1;

	/* �� */
	UPROPERTY(VisibleAnywhere)
	int32 Strength = 1;

	/* ��ø�� */
	UPROPERTY(VisibleAnywhere)
	int32 Agility = 1;

	/* ���� */
	UPROPERTY(VisibleAnywhere)
	int32 Intelligence = 1;

	/* ���� ���� */
	UPROPERTY(VisibleAnywhere)
	int32 PhysicalDefense = 1;

	/* ���� ���� */
	UPROPERTY(VisibleAnywhere)
	int32 MagicDefense = 1;
};

class MULTIPLAYER_API CharacterInformation
{
public:
	CharacterInformation();
	~CharacterInformation();
};
