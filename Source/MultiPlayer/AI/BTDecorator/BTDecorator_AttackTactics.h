#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_AttackTactics.generated.h"

UCLASS()
class MULTIPLAYER_API UBTDecorator_AttackTactics : public UBTDecorator
{
	GENERATED_BODY()

public :
	UBTDecorator_AttackTactics();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
