#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "CheckExtraAttack.generated.h"

UCLASS()
class MULTIPLAYER_API UCheckExtraAttack : public UAnimNotify
{
	GENERATED_BODY()
	
public :
	FString GetNotifyName_Implementation() const override;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
};
