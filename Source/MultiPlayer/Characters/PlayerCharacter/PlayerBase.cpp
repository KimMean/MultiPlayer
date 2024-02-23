#include "Characters/PlayerCharacter/PlayerBase.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

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
	
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem != nullptr)
		{
			Subsystem->AddMappingContext(InputMapping, 0);
			DebugLog::Print("AddMappingContext");
		}
	}
	
}

void APlayerBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (input == nullptr) return;

	input->BindAction(InputActions.FindRef("Move"), ETriggerEvent::Triggered, this, &APlayerBase::OnMove);

	DebugLog::Print("SetupPlayerInputComponent");
}

void APlayerBase::OnMove(const FInputActionInstance& Instance)
{
	DebugLog::Print(Instance.GetValue().Get<FVector2D>());

	FVector2D moveDirection = Instance.GetValue().Get<FVector2D>();

	AddMovementInput(GetActorRightVector(), moveDirection.X);
	AddMovementInput(GetActorForwardVector(), moveDirection.Y);
}
