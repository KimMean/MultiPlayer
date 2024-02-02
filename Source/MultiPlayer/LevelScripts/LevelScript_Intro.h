#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelScript_Intro.generated.h"

class UIntroMain;

UCLASS()
class MULTIPLAYER_API ALevelScript_Intro : public ALevelScriptActor
{
	GENERATED_BODY()
	
public :
	ALevelScript_Intro();

protected :
	virtual void BeginPlay() override;

private:
	TSubclassOf<UIntroMain> MainWidgetClass;
};
