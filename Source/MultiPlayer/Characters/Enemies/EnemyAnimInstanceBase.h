#pragma once

#include "CoreMinimal.h"
#include "Characters/AnimInstanceBase.h"
#include "EnemyAnimInstanceBase.generated.h"

class AEnemyBase;

UCLASS()
class MULTIPLAYER_API UEnemyAnimInstanceBase : public UAnimInstanceBase
{
	GENERATED_BODY()

public :
	// ~Begin AnimInstance Interface
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	// ~End AnimInstance Interface

};
