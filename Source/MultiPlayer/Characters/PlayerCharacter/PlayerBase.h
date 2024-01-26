#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "PlayerBase.generated.h"

UCLASS()
class MULTIPLAYER_API APlayerBase : public ACharacterBase
{
	GENERATED_BODY()
	
public :
	APlayerBase();

protected :
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void OnMoveForward(float InAxis);
	void OnMoveRight(float InAxis);
};
