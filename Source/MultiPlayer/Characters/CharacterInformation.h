#pragma once

#include "CoreMinimal.h"
#include "CharacterInformation.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStatus
{
	GENERATED_BODY()

public:
	/* 닉네임 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString PlayerName;

	///* 레벨 */
	//UPROPERTY(EditAnywhere)
	//int32 Level;

	///* 경험치 */
	//UPROPERTY(EditAnywhere)
	//float Experience;

	/* 체력 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 HealthPoint;

	/* 마나 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MagicPoint;

	/* 힘 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Strength = 10;

	/* 지능 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 Intelligence = 10;

	/* 물리 방어력 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 PhysicalDef = 10;

	/* 마법 방어력 */
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 MagicDef = 10;
};

class MULTIPLAYER_API CharacterInformation
{
public:
	CharacterInformation();
	~CharacterInformation();
};
