#include "UserInterface/Lobby/LobbyMain.h"

#include "Components/Button.h"
#include "GameSetting/Controllers/ControllerBase.h"

void ULobbyMain::NativeConstruct()
{
	Super::NativeConstruct();


	//Btn_OnlineServer->OnClicked.AddDynamic(this, &ULobbyMain::OnlineServerButtonOnClick);
	//Btn_HostServer->OnClicked.AddDynamic(this, &ULobbyMain::HostServerButtonOnClick);
	//Btn_JoinServer->OnClicked.AddDynamic(this, &ULobbyMain::JoinServerButtonOnClick);
	//Btn_Option->OnClicked.AddDynamic(this, &ULobbyMain::OptionButtonOnClick);
	//Btn_Quit->OnClicked.AddDynamic(this, &ULobbyMain::QuitButtonOnClick);
	Btn_Join->OnClicked.AddDynamic(this, &ULobbyMain::JoinButtonOnClick);
}


void ULobbyMain::ProfileButtonOnClick()
{
}

void ULobbyMain::InventoryButtonOnClick()
{
}

void ULobbyMain::StoreButtonOnClick()
{
}

void ULobbyMain::OptionButtonOnClick()
{
}

void ULobbyMain::JoinButtonOnClick()
{
	Cast<AControllerBase>(GetOwningPlayer())->JoinServer();
	// °Ù ÄÁÆ®·Ñ·¯ Client Travel
}

void ULobbyMain::ChangeButtonOnClick()
{
}

void ULobbyMain::QuitButtonOnClick()
{
}

void ULobbyMain::ReadyButtonOnClick()
{
}
