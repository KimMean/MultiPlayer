#pragma once

#include "CoreMinimal.h"
#include "Characters/PlayerCharacter/PlayerBase.h"
#include "Manny.generated.h"

class UCameraControlComponent;

UCLASS()
class MULTIPLAYER_API AManny : public APlayerBase
{
	GENERATED_BODY()
	
public :
	AManny();

protected :
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

private :
	UCameraControlComponent* CameraComponent;
};
