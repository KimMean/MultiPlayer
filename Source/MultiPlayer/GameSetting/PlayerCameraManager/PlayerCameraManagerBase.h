#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "PlayerCameraManagerBase.generated.h"

UCLASS()
class MULTIPLAYER_API APlayerCameraManagerBase : public APlayerCameraManager
{
	GENERATED_BODY()
	
public :
	APlayerCameraManagerBase();
};
