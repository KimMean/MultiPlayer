#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "LaunchCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API ULaunchCharacter : public UAnimNotify
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Velocity = FVector::ZeroVector;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	float Distance = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bXYOverride = true;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bZOverride = true;

public:
	ULaunchCharacter();

private:
	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
