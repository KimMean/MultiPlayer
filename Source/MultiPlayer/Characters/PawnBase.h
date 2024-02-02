#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

class UCameraComponent;

UCLASS()
class MULTIPLAYER_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	APawnBase();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly)
		USceneComponent* SceneComponent;

	UPROPERTY(VisibleDefaultsOnly)
		UCameraComponent* CameraComponent;
};
