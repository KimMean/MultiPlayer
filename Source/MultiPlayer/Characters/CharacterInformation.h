#pragma once

#include "CoreMinimal.h"
#include "CharacterInformation.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStatus : public FTableRowBase
{
	GENERATED_BODY()

public:
	/* �г��� */
	UPROPERTY(EditDefaultsOnly)
	FString CharacterName = "Character";

	/* ���� */
	UPROPERTY(EditDefaultsOnly)
	int32 Level = 1;

	/* ����ġ */
	UPROPERTY(EditDefaultsOnly)
	float Experience = 1;

	/* ü�� */
	UPROPERTY(EditDefaultsOnly)
	int32 HealthPoint = 1;

	/* ���� */
	UPROPERTY(EditDefaultsOnly)
	int32 MagicPoint = 1;

	/* �� */
	UPROPERTY(EditDefaultsOnly)
	int32 Strength = 1;

	/* ���� */
	UPROPERTY(EditDefaultsOnly)
	int32 Intelligence = 1;

	/* ���� ���� */
	UPROPERTY(EditDefaultsOnly)
	int32 PhysicalDefense = 1;

	/* ���� ���� */
	UPROPERTY(EditDefaultsOnly)
	int32 MagicDefense = 1;
};

class MULTIPLAYER_API CharacterInformation
{
public:
	CharacterInformation();
	~CharacterInformation();
};
