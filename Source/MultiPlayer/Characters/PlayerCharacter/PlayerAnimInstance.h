#pragma once

#include "CoreMinimal.h"
#include "Characters/AnimInstanceBase.h"
#include "Enums/DirectionState.h"
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
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TWeakObjectPtr<APlayerBase> OwnerCharacter = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TEnumAsByte<EDirectionState> MoveDirection;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bEvation = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bAttacking = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bSmashing = false;

	/**
	* Min : 1
	* Max : MAX_ATTACK_COMBO
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int AttackCombo = 0;

public:
	UPlayerAnimInstance();
	virtual void NativeBeginPlay() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;


};