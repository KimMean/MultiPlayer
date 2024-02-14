#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ResetEvationState.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UResetEvationState : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	UResetEvationState();

private:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
