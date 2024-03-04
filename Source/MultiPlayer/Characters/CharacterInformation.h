#pragma once

#include "CoreMinimal.h"
#include "CharacterInformation.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStatus : public FTableRowBase
{
	GENERATED_BODY()

public:
	/* 닉네임 */
	UPROPERTY(EditDefaultsOnly)
	FString CharacterName = "Character";

	/* 레벨 */
	UPROPERTY(EditDefaultsOnly)
	int32 Level = 1;

	/* 경험치 */
	UPROPERTY(EditDefaultsOnly)
	float Experience = 1;

	/* 체력 */
	UPROPERTY(EditDefaultsOnly)
	int32 HealthPoint = 1;

	/* 마나 */
	UPROPERTY(EditDefaultsOnly)
	int32 MagicPoint = 1;

	/* 힘 */
	UPROPERTY(EditDefaultsOnly)
	int32 Strength = 1;

	/* 지능 */
	UPROPERTY(EditDefaultsOnly)
	int32 Intelligence = 1;

	/* 물리 방어력 */
	UPROPERTY(EditDefaultsOnly)
	int32 PhysicalDefense = 1;

	/* 마법 방어력 */
	UPROPERTY(EditDefaultsOnly)
	int32 MagicDefense = 1;
};

class MULTIPLAYER_API CharacterInformation
{
public:
	CharacterInformation();
	~CharacterInformation();
};
