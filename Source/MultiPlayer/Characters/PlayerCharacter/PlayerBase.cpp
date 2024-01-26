#include "Characters/PlayerCharacter/PlayerBase.h"
#include "Kismet/KismetMathLibrary.h"
#include "Engine.h"

APlayerBase::APlayerBase()
{
}

void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Move Forward", this, &APlayerBase::OnMoveForward);
	PlayerInputComponent->BindAxis("Move Right", this, &APlayerBase::OnMoveRight);
}

void APlayerBase::OnMoveForward(float InAxis)
{
	FVector direction = UKismetMathLibrary::GetForwardVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f));
	AddMovementInput(direction, InAxis);
}

void APlayerBase::OnMoveRight(float InAxis)
{
	FVector direction = UKismetMathLibrary::GetRightVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f));
	AddMovementInput(direction, InAxis);
}
