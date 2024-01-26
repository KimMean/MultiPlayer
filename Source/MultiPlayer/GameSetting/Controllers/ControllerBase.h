#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ControllerBase.generated.h"

UCLASS()
class MULTIPLAYER_API AControllerBase : public APlayerController
{
	GENERATED_BODY()
	
public :
	AControllerBase(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
};
