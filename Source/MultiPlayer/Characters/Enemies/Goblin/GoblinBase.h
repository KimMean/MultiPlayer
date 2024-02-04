#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemies/EnemyBase.h"
#include "GoblinBase.generated.h"

UCLASS()
class MULTIPLAYER_API AGoblinBase : public AEnemyBase
{
	GENERATED_BODY()

public:
	AGoblinBase();

protected :
	virtual void BeginPlay() override;
};
