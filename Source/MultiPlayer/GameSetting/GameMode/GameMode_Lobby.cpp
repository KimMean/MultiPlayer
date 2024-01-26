#include "GameSetting/GameMode/GameMode_Lobby.h"

#include "GameSetting/Controllers/ControllerBase.h"

AGameMode_Lobby::AGameMode_Lobby()
{
	PlayerControllerClass = AControllerBase::StaticClass();
}

void AGameMode_Lobby::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void AGameMode_Lobby::BeginPlay()
{

}
