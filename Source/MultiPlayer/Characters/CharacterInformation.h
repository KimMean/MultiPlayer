#pragma once

#include "CoreMinimal.h"
#include "CharacterInformation.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStatus : public FTableRowBase
{
	GENERATED_BODY()

public:
	/* 닉네임 */
	UPROPERTY(VisibleAnywhere)
	FString CharacterName = "Character";

	/* 레벨 */
	UPROPERTY(VisibleAnywhere)
	int32 Level = 1;

	/* 경험치 */
	UPROPERTY(VisibleAnywhere)
	float Experience = 0;

	/* 체력 */
	UPROPERTY(VisibleAnywhere)
	int32 HealthPoint = 100;

	/* 마나 */
	UPROPERTY(VisibleAnywhere)
	int32 MagicPoint = 5;

	/* 힘 */
	UPROPERTY(VisibleAnywhere)
	int32 Strength = 5;

	/* 지능 */
	UPROPERTY(VisibleAnywhere)
	int32 Intelligence = 5;

	/* 물리 방어력 */
	UPROPERTY(VisibleAnywhere)
	int32 PhysicalDefense = 5;

	/* 마법 방어력 */
	UPROPERTY(VisibleAnywhere)
	int32 MagicDefense = 5;
};

class MULTIPLAYER_API CharacterInformation
{
public:
	CharacterInformation();
	~CharacterInformation();
};
