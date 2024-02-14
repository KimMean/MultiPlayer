#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Enums/CharacterState.h"
#include "Enums/DirectionState.h"
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
	TEnumAsByte<ECharacterState> CharacterState;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TEnumAsByte<EDirectionState> HitDirection;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Speed = 0.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	float Direction = 0.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bFalling = false;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	bool bSaveHit = false;

public:
	UAnimInstanceBase();
	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
};
