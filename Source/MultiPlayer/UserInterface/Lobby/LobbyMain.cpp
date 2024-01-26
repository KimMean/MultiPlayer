#include "UserInterface/Lobby/LobbyMain.h"

#include "Components/Button.h"

void ULobbyMain::NativeConstruct()
{
	Super::NativeConstruct();


	//Btn_OnlineServer->OnClicked.AddDynamic(this, &ULobbyMain::OnlineServerButtonOnClick);
	//Btn_HostServer->OnClicked.AddDynamic(this, &ULobbyMain::HostServerButtonOnClick);
	//Btn_JoinServer->OnClicked.AddDynamic(this, &ULobbyMain::JoinServerButtonOnClick);
	//Btn_Option->OnClicked.AddDynamic(this, &ULobbyMain::OptionButtonOnClick);
	//Btn_Quit->OnClicked.AddDynamic(this, &ULobbyMain::QuitButtonOnClick);
}

void ULobbyMain::OnlineServerButtonOnClick()
{
}

void ULobbyMain::HostServerButtonOnClick()
{
}

void ULobbyMain::JoinServerButtonOnClick()
{
}

void ULobbyMain::OptionButtonOnClick()
{
}

void ULobbyMain::QuitButtonOnClick()
{
}
