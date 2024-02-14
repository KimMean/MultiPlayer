#pragma once

#include "CoreMinimal.h"
#include "CharacterInformation.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStatus
{
	GENERATED_BODY()

public:
	/* �г��� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PlayerName;

	///* ���� */
	//UPROPERTY(EditAnywhere)
	//int32 Level;

	///* ����ġ */
	//UPROPERTY(EditAnywhere)
	//float Experience;

	/* ü�� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 HealthPoint;

	/* ���� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MagicPoint;

	/* �� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Strength = 10;

	/* ���� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Intelligence = 10;

	/* ���� ���� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 PhysicalDef = 10;

	/* ���� ���� */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MagicDef = 10;
};

class MULTIPLAYER_API CharacterInformation
{
public:
	CharacterInformation();
	~CharacterInformation();
};
