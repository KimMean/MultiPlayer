#include "LevelScripts/LevelScript_SelectCharacter.h"

#include "UserInterface/SelectCharacter/SelectCharacter.h"

ALevelScript_SelectCharacter::ALevelScript_SelectCharacter()
{
	ConstructorHelpers::FClassFinder<USelectCharacter> widget(TEXT("WidgetBlueprint'/Game/UI/SelectCharacter/WB_SelectCharacter.WB_SelectCharacter_C'"));
	MainWidgetClass = widget.Class;
}

void ALevelScript_SelectCharacter::BeginPlay()
{
	Super::BeginPlay();

	USelectCharacter* widget = CreateWidget<USelectCharacter>(GetWorld(), MainWidgetClass);
	
	if (widget)
		widget->AddToViewport();
}
