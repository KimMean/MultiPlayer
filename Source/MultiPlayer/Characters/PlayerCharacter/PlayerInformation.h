#pragma once

#include "CoreMinimal.h"
#include "PlayerInformation.generated.h"

USTRUCT()
struct MULTIPLAYER_API FPlayerInfo
{
	GENERATED_BODY()

public:
	/* �г��� */
	UPROPERTY(EditAnywhere)
		FString PlayerName;

	/* ���� */
	UPROPERTY(EditAnywhere)
		int32 Level;

	/* ����ġ */
	UPROPERTY(EditAnywhere)
		float Experience;

	/* ü�� */
	UPROPERTY(EditAnywhere)
		int32 HealthPoint;

	/* ���� */
	UPROPERTY(EditAnywhere)
		int32 MagicPoint;

	/* �� */
	UPROPERTY(EditAnywhere)
		int32 Strength;

	/* ���� */
	UPROPERTY(EditAnywhere)
		int32 Intelligence;

};


class MULTIPLAYER_API PlayerInformation
{
public:
	PlayerInformation();
	~PlayerInformation();
};
