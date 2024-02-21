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

	//~ Begin AEnemyBase Interface.
	virtual void PostInitializeComponents() override;
	//~ End AEnemyBase Interface.

protected:
	virtual void BeginPlay() override;
};
