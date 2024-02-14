#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_CanAttack.generated.h"

UCLASS()
class MULTIPLAYER_API UBTD_CanAttack : public UBTDecorator
{
	GENERATED_BODY()
	
public :
	UBTD_CanAttack();

protected :
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
};
