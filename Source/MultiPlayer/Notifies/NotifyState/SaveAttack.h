#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "SaveAttack.generated.h"

/**
 * 
 */
class APlayerBase;

UCLASS()
class MULTIPLAYER_API USaveAttack : public UAnimNotifyState
{
	GENERATED_BODY()
	
public:
	USaveAttack();

private:
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference) override;
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;

private:
	APlayerBase* Character = nullptr;
	bool bComboCheck = false;
};
