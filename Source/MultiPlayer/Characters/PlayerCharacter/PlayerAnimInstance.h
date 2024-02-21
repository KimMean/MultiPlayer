#pragma once

#include "CoreMinimal.h"
#include "Characters/AnimInstanceBase.h"
#include "PlayerAnimInstance.generated.h"

/**
 * 
 */
class APlayerBase;

UCLASS()
class MULTIPLAYER_API UPlayerAnimInstance : public UAnimInstanceBase
{
	GENERATED_BODY()

protected:

public:
	UPlayerAnimInstance();
	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


};