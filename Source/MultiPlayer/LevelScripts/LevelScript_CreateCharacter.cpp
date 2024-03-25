#include "LevelScripts/LevelScript_CreateCharacter.h"

#include "UserInterface/CreateCharacter/WCreateCharacter.h"

ALevelScript_CreateCharacter::ALevelScript_CreateCharacter()
{
	ConstructorHelpers::FClassFinder<UWCreateCharacter> widget(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/CreateCharacter/WB_CreateCharacter.WB_CreateCharacter_C'"));
	MainWidgetClass = widget.Class;
}

void ALevelScript_CreateCharacter::BeginPlay()
{
	Super::BeginPlay();

	Widget = CreateWidget<UWCreateCharacter>(GetWorld(), MainWidgetClass);

	if (Widget)
		Widget->AddToViewport();
}

