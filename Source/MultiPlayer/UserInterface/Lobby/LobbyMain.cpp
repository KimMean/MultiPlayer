#include "UserInterface/Lobby/LobbyMain.h"

#include "Components/Button.h"
#include "GameSetting/Controllers/ControllerBase.h"
#include "System/OnlineSubsystem/SteamSystem.h"

void ULobbyMain::NativeConstruct()
{
	Super::NativeConstruct();


	//Btn_OnlineServer->OnClicked.AddDynamic(this, &ULobbyMain::OnlineServerButtonOnClick);
	//Btn_HostServer->OnClicked.AddDynamic(this, &ULobbyMain::HostServerButtonOnClick);
	//Btn_JoinServer->OnClicked.AddDynamic(this, &ULobbyMain::JoinServerButtonOnClick);
	Btn_Option->OnClicked.AddDynamic(this, &ULobbyMain::OptionButtonOnClick);
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
	GetGameInstance()->GetSubsystem<USteamSystem>()->CreateSession();
}

void ULobbyMain::JoinButtonOnClick()
{
	//Cast<AControllerBase>(GetOwningPlayer())->JoinServer();
	// °Ù ÄÁÆ®·Ñ·¯ Client Travel
	GetGameInstance()->GetSubsystem<USteamSystem>()->JoinSession();
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
