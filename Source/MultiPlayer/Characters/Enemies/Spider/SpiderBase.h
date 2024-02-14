#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemies/EnemyBase.h"
#include "SpiderBase.generated.h"

UCLASS()
class MULTIPLAYER_API ASpiderBase : public AEnemyBase
{
	GENERATED_BODY()

public:
	ASpiderBase();

protected:
	virtual void BeginPlay() override;
};
