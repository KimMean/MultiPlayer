#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Enums/CharacterState.h"
#include "BTTN_PlayAnimation.generated.h"

/*
* Only Enemy class
* need AnimationComponent
*/
UCLASS()
class MULTIPLAYER_API UBTTN_PlayAnimation : public UBTTaskNode
{
	GENERATED_BODY()
	
public :
	UBTTN_PlayAnimation();

protected :
	// ~Begin UBTTaskNode
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

	virtual void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	// ~End UBTTaskNode

protected :
	UPROPERTY(EditAnywhere)
		ECharacterState StateType;

};
