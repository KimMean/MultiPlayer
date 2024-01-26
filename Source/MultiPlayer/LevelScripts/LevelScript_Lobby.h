#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelScript_Lobby.generated.h"

class ULobbyMain;

UCLASS()
class MULTIPLAYER_API ALevelScript_Lobby : public ALevelScriptActor
{
	GENERATED_BODY()
	
public :
	ALevelScript_Lobby();

protected :
	virtual void BeginPlay() override;

private:
	TSubclassOf<ULobbyMain> MainWidgetClass;
};
