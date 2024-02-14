#include "AI/BTComposite/BTC_RandomSelector.h"

UBTC_RandomSelector::UBTC_RandomSelector()
{
	NodeName = "Random Selector";
}

int32 UBTC_RandomSelector::GetNextChildHandler(FBehaviorTreeSearchData& SearchData, int32 PrevChild, EBTNodeResult::Type LastResult) const
{
	int32 NextChildIdx = BTSpecialChild::ReturnToParent;

	if (PrevChild == BTSpecialChild::NotInitialized)
	{
		// newly activated: start from first
		NextChildIdx = FMath::RandRange(0, GetChildrenNum() - 1);
	}

	return NextChildIdx;
}


