#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "ControlAnimRateScale.generated.h"

/**
 * 
 */
class UCurveFloat;

UCLASS()
class MULTIPLAYER_API UControlAnimRateScale : public UAnimNotifyState
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TWeakObjectPtr<UCurveFloat> Curve = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bTakeOverRateScale = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float StartRateScale = 1.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float EndRateScale = 1.0f;

public:
	UControlAnimRateScale();

private:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

private:
	float Duration = 0.0f;
	float CurTime = 0.0f;
	float CurveDuration = 0.0f;
};
