#include "LevelScripts/LevelScript_Initialized.h"

#include "Kismet/GameplayStatics.h"
#include "Blueprint/UserWidget.h"

#include "System/DataSystem/SaveSystem.h"
#include "Utilities/DebugLog.h"

ALevelScript_Initialized::ALevelScript_Initialized()
{
	ConstructorHelpers::FClassFinder<UUserWidget> widget(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/Initialized/WB_Initialize.WB_Initialize_C'"));
	MainWidgetClass = widget.Class;
}

void ALevelScript_Initialized::PreInitializeComponents()
{
	Super::PreInitializeComponents();
	DebugLog::Print("ALevelScript_Initialized : PreInitializeComponents");
	UUserWidget* widget = CreateWidget<UUserWidget>(GetWorld(), MainWidgetClass);

	if (widget)
		widget->AddToViewport();
}

void ALevelScript_Initialized::BeginPlay()
{
	Super::BeginPlay();
	DebugLog::Print("ALevelScript_Initialized : BeginPlay");
	// ��� ������ ��ü�� ���ε� �ϰ� ������ �� ����
	// �ʱ�ȭ �Ϸ�Ǹ� ĳ���� ����â���� �̵�


	if (USaveSystem* LoadedGame = Cast<USaveSystem>(UGameplayStatics::LoadGameFromSlot(TEXT("PlayerOne1"), 0)))
	{
		// The operation was successful, so LoadedGame now contains the data we saved earlier.
		//DebugLog::Print(*LoadedGame->GetPlayerName());
		//UE_LOG(LogTemp, Warning, TEXT("LOADED: %s"), *LoadedGame->PlayerName);
	}

	UGameplayStatics::OpenLevel(GetWorld(), FName("SelectCharacter"));


}