#pragma once

#include "CoreMinimal.h"
#include "PlayerInformation.generated.h"

USTRUCT()
struct MULTIPLAYER_API FPlayerInfo
{
	GENERATED_BODY()

public:
	/* 닉네임 */
	UPROPERTY(EditAnywhere)
		FString PlayerName;

	/* 레벨 */
	UPROPERTY(EditAnywhere)
		int32 Level;

	/* 경험치 */
	UPROPERTY(EditAnywhere)
		float Experience;

	/* 체력 */
	UPROPERTY(EditAnywhere)
		int32 HealthPoint;

	/* 마나 */
	UPROPERTY(EditAnywhere)
		int32 MagicPoint;

	/* 힘 */
	UPROPERTY(EditAnywhere)
		int32 Strength;

	/* 지능 */
	UPROPERTY(EditAnywhere)
		int32 Intelligence;

};


class MULTIPLAYER_API PlayerInformation
{
public:
	PlayerInformation();
	~PlayerInformation();
};
