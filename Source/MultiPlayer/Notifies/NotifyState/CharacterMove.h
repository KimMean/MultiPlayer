#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "CharacterMove.generated.h"

/**
 * 
 */
class AChracterBase;

UCLASS()
class MULTIPLAYER_API UCharacterMove : public UAnimNotifyState
{
	GENERATED_BODY()
	
protected:
	/**
	* If bConservation is true, the option is invalid.
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Direction = FVector::ZeroVector;

	/**
	* If bConservation is true, the option is invalid.
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float IncreaseSpeed = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bDirectionConservation = false;

	//UPROPERTY(BlueprintReadWrite, EditAnywhere)
	//bool bSpeedConservation = false;

public:
	UCharacterMove();

private:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

private:
	ACharacterBase* Character = nullptr;

	FVector MoveDirection = FVector::ZeroVector;
};
