#include "UserInterface/SelectCharacter/CreateCharacter.h"

#include "Components/Button.h"

void UCreateCharacter::NativeConstruct()
{
	Btn_Create->OnClicked.AddDynamic(this, &UCreateCharacter::Btn_Create_OnClick);
}

void UCreateCharacter::Btn_Create_OnClick()
{
	// CreateWidget¿∏∑Œ ~
}
