#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "PlayerBase.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;

struct FInputActionInstance;

UCLASS()
class MULTIPLAYER_API APlayerBase : public ACharacterBase
{
	GENERATED_BODY()

protected:
	//UPROPERTY(BlueprintReadOnly, EditAnywhere)
	//UCameraControlComponent* CameraComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Component")
	USpringArmComponent* SpringArm = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Component")
	UCameraComponent* Camera = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	TMap<FString, UInputAction*> InputActions;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	float VerticalLookRate = 10.0f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Input")
	float HorizontalLookRate = 10.0f;

public:
	APlayerBase();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void OnForwardMove(const FInputActionInstance& Instance);
	void OnRightMove(const FInputActionInstance& Instance);

	void VerticalLook(const FInputActionInstance& Instance);
	void HorizontalLook(const FInputActionInstance& Instance);

	void OnMove(const FInputActionInstance& Instance);
	void OnTest(const FInputActionInstance& Instance);
};
