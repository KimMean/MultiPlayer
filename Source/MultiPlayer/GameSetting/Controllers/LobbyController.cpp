#include "GameSetting/Controllers/LobbyController.h"

#include "Utilities/DebugLog.h"

ALobbyController::ALobbyController()
{
	//bShowMouseCursor = false;
}

void ALobbyController::BeginPlay()
{
}

void ALobbyController::JoinServer()
{
	Super::JoinServer();
	FString JoinAddress = "127.0.0.1:7777";
	ClientTravel(JoinAddress, ETravelType::TRAVEL_Absolute);
}

void ALobbyController::SeamlessTravelTo(APlayerController* NewPC)
{
	Super::SeamlessTravelTo(NewPC);
	DebugLog::Print("SeamlessTravelTo");
}

void ALobbyController::SeamlessTravelFrom(APlayerController* OldPC)
{
	Super::SeamlessTravelFrom(OldPC);
	DebugLog::Print("SeamlessTravelFrom");
}

void ALobbyController::PostSeamlessTravel()
{
	Super::PostSeamlessTravel();
	DebugLog::Print("PostSeamlessTravel");
}
