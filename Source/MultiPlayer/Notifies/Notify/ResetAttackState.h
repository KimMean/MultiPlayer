#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ResetAttackState.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API UResetAttackState : public UAnimNotify
{
	GENERATED_BODY()

public:
	UResetAttackState();

private:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
