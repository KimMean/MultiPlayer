#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Components/Enemy/EnemyStateComponent.h"
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
	void PlayAnimMontage(EEnemyStateType InState);

private:
	UPROPERTY(EditDefaultsOnly)
		TObjectPtr<UEnemyAnimationData> AnimDatas;

		
};
