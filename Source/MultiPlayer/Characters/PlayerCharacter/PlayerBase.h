#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "PlayerBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

class AWeaponBase;

struct FInputActionInstance;

UCLASS()
class MULTIPLAYER_API APlayerBase : public ACharacterBase
{
	GENERATED_BODY()



public:
	APlayerBase();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private :
	void OnMove(const FInputActionInstance& Instance);

protected:
	UPROPERTY(EditAnywhere, Category = "Player|Component")
		TObjectPtr<USpringArmComponent> SpringArm = nullptr;

	UPROPERTY(EditAnywhere, Category = "Player|Component")
		TObjectPtr<UCameraComponent> Camera = nullptr;

protected :
	/* Player Input Mapping Context */
	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputMappingContext> InputMapping;

	/* Player Input Action */
	UPROPERTY(EditAnywhere, Category = "Input")
		TMap<FString, TObjectPtr<UInputAction>> InputActions;
};
