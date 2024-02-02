#include "UserInterface/Intro/IntroMain.h"

#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UIntroMain::NativeConstruct()
{
	Super::NativeConstruct();

	Btn_Check->OnClicked.AddDynamic(this, &UIntroMain::Btn_Check_OnClicked);
}

void UIntroMain::Btn_Check_OnClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("SelectCharacter"));
	//UGameplayStatics::OpenLevel(GetWorld(), FName("SelectCharacter"), true, ((FString)(L"Listen")));
}
