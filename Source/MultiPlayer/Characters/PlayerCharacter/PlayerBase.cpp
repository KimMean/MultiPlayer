#include "Characters/PlayerCharacter/PlayerBase.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "Utilities/DebugLog.h"

APlayerBase::APlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));

	if (mesh.Succeeded() == true)
	{
		GetMesh()->SetSkeletalMesh(mesh.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
		GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	{
		SpringArm->SetupAttachment(RootComponent);
		Camera->SetupAttachment(SpringArm);

		SpringArm->TargetArmLength = 300.0f;
		SpringArm->SocketOffset.Z = 150.0f;
		SpringArm->bUsePawnControlRotation = true;
		SpringArm->bInheritPitch = true;
		SpringArm->bInheritRoll = true;
		SpringArm->bInheritYaw = true;
		SpringArm->bDoCollisionTest = true;

		Camera->AddRelativeRotation(FRotator(-10.0f, 0.0f, 0.0f));

		bUseControllerRotationYaw = true;
	}
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
	UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (input == nullptr) return;

	input->BindAction(InputActions.FindRef("ForwardMove"), ETriggerEvent::Triggered, this, &APlayerBase::OnForwardMove);
	input->BindAction(InputActions.FindRef("RightMove"), ETriggerEvent::Triggered, this, &APlayerBase::OnRightMove);
	
	input->BindAction(InputActions.FindRef("VerticalLook"), ETriggerEvent::Triggered, this, &APlayerBase::VerticalLook);
	input->BindAction(InputActions.FindRef("HorizontalLook"), ETriggerEvent::Triggered, this, &APlayerBase::HorizontalLook);
}

//void APlayerBase::OnMoveForward(float InAxis)
//{
//	FVector direction = UKismetMathLibrary::GetForwardVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f));
//	AddMovementInput(direction, InAxis);
//}
//
//void APlayerBase::OnMoveRight(float InAxis)
//{
//	FVector direction = UKismetMathLibrary::GetRightVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f));
//	AddMovementInput(direction, InAxis);
//}

void APlayerBase::OnForwardMove(const FInputActionInstance& Instance)
{
	FVector value = Instance.GetValue().Get<FVector>();

	FVector forward = GetActorForwardVector();
	float speed = 200.0f;
	
	AddMovementInput(forward * speed * value.X);
}

void APlayerBase::OnRightMove(const FInputActionInstance& Instance)
{
	FVector value = Instance.GetValue().Get<FVector>();
	
	FVector right = GetActorRightVector();
	float speed = 200.0f;
	AddMovementInput(right * speed * value.X);
}

void APlayerBase::VerticalLook(const FInputActionInstance& Instance)
{
	FVector value = Instance.GetValue().Get<FVector>();
	float pitch = VerticalLookRate * value.X * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());

	AddControllerPitchInput(pitch);
}

void APlayerBase::HorizontalLook(const FInputActionInstance& Instance)
{
	FVector value = Instance.GetValue().Get<FVector>();
	float yaw = HorizontalLookRate * value.X * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());

	AddControllerYawInput(yaw);
}

void APlayerBase::OnMove(const FInputActionInstance& Instance)
{
	FVector testVector = Instance.GetValue().Get<FVector>();
	bool testBool = Instance.GetValue().Get<bool>();

	FString value = (testBool == true ? L"True" : L"False");
	FString testLog = L"";
	testLog = L"Bool Check : " + value;
	testLog += L"\nVector Check : " + testVector.ToString();
	DebugLog::Print(testLog, -1, 0.01f, FColor::Red);

	FVector forward = GetActorForwardVector();
	float speed = 200.0f;
	AddMovementInput(forward * speed);
}

void APlayerBase::OnTest(const FInputActionInstance& Instance)
{
	DebugLog::Print(L"Test");
}
