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
	TWeakObjectPtr<ACharacterBase> Character = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Speed = 0.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Direction = 0.0f;


public:
	UAnimInstanceBase();
	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
