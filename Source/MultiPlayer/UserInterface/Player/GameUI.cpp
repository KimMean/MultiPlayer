#include "UserInterface/Player/GameUI.h"

#include "UserInterface/Player/Player_HealthPoint.h"
#include "Utilities/DebugLog.h"

void UGameUI::NativeConstruct()
{
}

void UGameUI::ModifyHealthPointPercent(float InPercent)
{
	WB_Player_HP->ModifyHealthPointPercent(InPercent);
}

void UGameUI::ModifyHealthPointPercent(float InCurValue, float InMaxValue)
{
	WB_Player_HP->ModifyHealthPointPercent(InCurValue / InMaxValue);
}
