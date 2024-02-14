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
	* 하위노드 중 하나를 랜덤으로 선택해서 실행합니다.
	*/
	virtual int32 GetNextChildHandler(struct FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const override;
};
