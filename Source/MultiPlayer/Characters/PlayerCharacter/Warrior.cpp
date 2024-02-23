#include "Characters/PlayerCharacter/Warrior.h"

#include "Components/SkeletalMeshComponent.h"

AWarrior::AWarrior()
{
	
	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Pirate/Meshes/SKM_Pirate.SKM_Pirate'"));

	if (mesh.Succeeded() == true)
	{
		GetMesh()->SetSkeletalMesh(mesh.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
		GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	}
}

void AWarrior::BeginPlay()
{
	Super::BeginPlay();
}

void AWarrior::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

