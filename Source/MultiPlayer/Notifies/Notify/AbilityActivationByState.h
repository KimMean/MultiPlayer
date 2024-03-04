#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "Enums/CharacterState.h"
#include "AbilityActivationByState.generated.h"

UCLASS()
class MULTIPLAYER_API UAbilityActivationByState : public UAnimNotify
{
	GENERATED_BODY()

public:
	// ~Begin UAnimNotify Interface
	FString GetNotifyName_Implementation() const override;

	virtual void Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference) override;
	// ~End UAnimNotify Interface

private:
	UPROPERTY(EditAnywhere)
		ECharacterState CharacterState;
};
