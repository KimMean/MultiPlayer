#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enums/CharacterState.h"
#include "EnemyAnimationComponent.generated.h"

class UEnemyAnimationData;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYER_API UEnemyAnimationComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UEnemyAnimationComponent();

protected:
	virtual void BeginPlay() override;

public :
	void PlayAnimation_Action();

public:
	/* TMap<ECharacterState, TArray<AnimationMontage> */
	void PlayAnimMontage(ECharacterState InState);

private:
	/* Animation Montage Data */
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UEnemyAnimationData> AnimDatas;

		
};
