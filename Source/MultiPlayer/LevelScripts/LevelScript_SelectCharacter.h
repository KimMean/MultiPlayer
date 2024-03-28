#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "LevelScript_SelectCharacter.generated.h"

class USelectCharacter;

UCLASS()
class MULTIPLAYER_API ALevelScript_SelectCharacter : public ALevelScriptActor
{
	GENERATED_BODY()

public :
	ALevelScript_SelectCharacter();

protected :
	virtual void BeginPlay() override;

};
