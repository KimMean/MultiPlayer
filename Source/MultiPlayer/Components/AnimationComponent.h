#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enums/CharacterState.h"
#include "AnimationComponent.generated.h"

class UEnemyAnimationData;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYER_API UAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UAnimationComponent();

protected:
	virtual void BeginPlay() override;


public:
	/* TMap<ECharacterState, TArray<AnimationMontage> */
	void PlayAnimMontage(ECharacterState InState);

private:
	/* Animation Montage Data */
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UEnemyAnimationData> AnimDatas;
};
