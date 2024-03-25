#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelScript_Initialized.generated.h"

class UUserWidget;

UCLASS()
class MULTIPLAYER_API ALevelScript_Initialized : public ALevelScriptActor
{
	GENERATED_BODY()
	
public :
	ALevelScript_Initialized();

	virtual void PreInitializeComponents() override;

protected:
	virtual void BeginPlay() override;

private:
	TSubclassOf<UUserWidget> MainWidgetClass;
};
