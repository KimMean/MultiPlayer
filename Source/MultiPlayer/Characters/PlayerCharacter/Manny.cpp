#include "Characters/PlayerCharacter/Manny.h"

#include "Characters/PlayerCharacter/Components/CameraControlComponent.h"

AManny::AManny()
{
	CameraComponent = CreateDefaultSubobject<UCameraControlComponent>(TEXT("CameraControlComponent"));

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));

	GetMesh()->SetSkeletalMesh(mesh.Object);
	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
}

void AManny::BeginPlay()
{
	PossessedBy(GetWorld()->GetFirstPlayerController());
}

void AManny::Tick(float DeltaSeconds)
{
	// PrimaryActorTick.bCanEverTick set true;
}

