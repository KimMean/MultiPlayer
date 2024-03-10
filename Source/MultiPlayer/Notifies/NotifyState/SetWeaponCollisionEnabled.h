#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotifyState.h"
#include "Enums/WeaponType.h"
#include "SetWeaponCollisionEnabled.generated.h"

/**
 * This class calls the SetCollisionEnabled function of the WeaponBase class.
 */
UCLASS()
class MULTIPLAYER_API USetWeaponCollisionEnabled : public UAnimNotifyState
{
	GENERATED_BODY()
	
public :
	FString GetNotifyName_Implementation() const override;

	// ~Begin UAnimNotifyState Interface
	virtual void NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference);
	//virtual void NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference);
	virtual void NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference);
	// ~End UAnimNotifyState Interface

protected :
	UPROPERTY(EditAnywhere)
		EWeaponType WeaponType;
};
