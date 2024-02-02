#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SpectatorPawn.h"
#include "SpectatorBase.generated.h"

UCLASS()
class MULTIPLAYER_API ASpectatorBase : public ASpectatorPawn
{
	GENERATED_BODY()
	
public :
	ASpectatorBase();
};
