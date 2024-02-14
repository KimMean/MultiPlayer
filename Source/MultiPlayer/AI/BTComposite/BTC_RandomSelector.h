#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BTC_RandomSelector.generated.h"

UCLASS()
class MULTIPLAYER_API UBTC_RandomSelector : public UBTCompositeNode
{
	GENERATED_BODY()
	
public :
	UBTC_RandomSelector();

	/* Random Selector
	* ������� �� �ϳ��� �������� �����ؼ� �����մϴ�.
	*/
	virtual int32 GetNextChildHandler(struct FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const override;
};
