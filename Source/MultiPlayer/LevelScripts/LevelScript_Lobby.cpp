#include "LevelScripts/LevelScript_Lobby.h"

#include "UserInterface/Lobby/LobbyMain.h"

ALevelScript_Lobby::ALevelScript_Lobby()
{
	ConstructorHelpers::FClassFinder<ULobbyMain> widget(TEXT("WidgetBlueprint'/Game/UI/Lobby/WB_Lobby.WB_Lobby_C'"));
	MainWidgetClass = widget.Class;
}

void ALevelScript_Lobby::BeginPlay()
{
	Super::BeginPlay();

	ULobbyMain* widget = CreateWidget<ULobbyMain>(GetWorld(), MainWidgetClass);

	if (widget)
		widget->AddToViewport();
}
