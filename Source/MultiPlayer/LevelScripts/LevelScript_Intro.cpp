#include "LevelScripts/LevelScript_Intro.h"

#include "Kismet/GameplayStatics.h"
#include "UserInterface/Intro/IntroMain.h"


ALevelScript_Intro::ALevelScript_Intro()
{
	ConstructorHelpers::FClassFinder<UIntroMain> widget(TEXT("WidgetBlueprint'/Game/UI/Intro/WB_IntroMain.WB_IntroMain_C'"));
	MainWidgetClass = widget.Class;
}

void ALevelScript_Intro::BeginPlay()
{
	Super::BeginPlay();

	UIntroMain* widget = CreateWidget<UIntroMain>(GetWorld(), MainWidgetClass);

	if (widget)
		widget->AddToViewport();

	UGameplayStatics::OpenLevel(GetWorld(), FName("SelectCharacter"));
}
