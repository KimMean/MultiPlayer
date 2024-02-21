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

//USTRUCT(BlueprintType)
//struct FSkillInformation
//{
//	GENERATED_BODY()
//
//protected:
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//	UFunction Test;
//
//	UPROPERTY(BlueprintReadWrite, EditAnywhere)
//	TWeakPtr<UAnimMontage> SkillAnim;
//};

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

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Component")
		TObjectPtr<USpringArmComponent> SpringArm = nullptr;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Component")
		TObjectPtr<UCameraComponent> Camera = nullptr;
};
