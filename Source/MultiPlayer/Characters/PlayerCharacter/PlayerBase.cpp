#include "Characters/PlayerCharacter/PlayerBase.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
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
	
}
