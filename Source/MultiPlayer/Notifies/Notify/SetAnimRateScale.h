 #pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "SetAnimRateScale.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API USetAnimRateScale : public UAnimNotify
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float RateScale = 1.0f;

public:
	USetAnimRateScale();

private:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
