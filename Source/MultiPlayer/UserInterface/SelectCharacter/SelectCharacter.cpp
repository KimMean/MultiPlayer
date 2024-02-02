#include "UserInterface/SelectCharacter/SelectCharacter.h"

#include "Components/WidgetSwitcher.h"

void USelectCharacter::NativeConstruct()
{
	WS_Selects.Add(WS_Select_0);
	WS_Selects.Add(WS_Select_1);
	WS_Selects.Add(WS_Select_2);
	WS_Selects.Add(WS_Select_3);
	WS_Selects.Add(WS_Select_4);

	
}

void USelectCharacter::CreateCharacter_OnClick()
{
}
