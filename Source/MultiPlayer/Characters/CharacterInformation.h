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
	int32 HealthPoint = 100;

	/* ���� */
	UPROPERTY(VisibleAnywhere)
	int32 MagicPoint = 5;

	/* �� */
	UPROPERTY(VisibleAnywhere)
	int32 Strength = 5;

	/* ���� */
	UPROPERTY(VisibleAnywhere)
	int32 Intelligence = 5;

	/* ���� ���� */
	UPROPERTY(VisibleAnywhere)
	int32 PhysicalDefense = 5;

	/* ���� ���� */
	UPROPERTY(VisibleAnywhere)
	int32 MagicDefense = 5;
};

class MULTIPLAYER_API CharacterInformation
{
public:
	CharacterInformation();
	~CharacterInformation();
};
