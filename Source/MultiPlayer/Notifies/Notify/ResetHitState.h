#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ResetHitState.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UResetHitState : public UAnimNotify
{
	GENERATED_BODY()
	
public:
	UResetHitState();

private:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
