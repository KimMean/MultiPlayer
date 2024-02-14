#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstanceBase.generated.h"

class AEnemyBase;

UCLASS()
class MULTIPLAYER_API UEnemyAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

public :
	// ~Begin AnimInstance Interface
	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	// ~End AnimInstance Interface

protected :
	UPROPERTY(BlueprintReadOnly, Category = "Enemy|Animation|Property")
		float Direction;

	UPROPERTY(BlueprintReadOnly, Category = "Enemy|Animation|Property")
		float Speed;

private :
	TObjectPtr<AEnemyBase> OwnerEnemy;
};
