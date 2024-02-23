#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AnimInstanceBase.generated.h"

/**
 * 
 */
class ACharacterBase;

UCLASS()
class MULTIPLAYER_API UAnimInstanceBase : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TObjectPtr<ACharacterBase> Character = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Speed = 0.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Direction = 0.0f;


public:
	UAnimInstanceBase();

	// ~Begin UAnimInstance Interface
	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	// ~End UAnimInstance Interface
};
