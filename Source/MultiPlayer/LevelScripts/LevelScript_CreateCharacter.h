#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelScript_CreateCharacter.generated.h"

class UWCreateCharacter;

UCLASS()
class MULTIPLAYER_API ALevelScript_CreateCharacter : public ALevelScriptActor
{
	GENERATED_BODY()
	
public :
	ALevelScript_CreateCharacter();

protected :
	virtual void BeginPlay() override;

protected :
	TSubclassOf<UWCreateCharacter> MainWidgetClass;
	TObjectPtr<UWCreateCharacter> Widget;
};
