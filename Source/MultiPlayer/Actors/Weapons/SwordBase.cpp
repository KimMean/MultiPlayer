#include "Actors/Weapons/SwordBase.h"
#include "Components/BoxComponent.h"


ASwordBase::ASwordBase()
{
	CollisionType = ECollisionType::Box;
	Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");

	Mesh->SetupAttachment(RootComponent);
	Collision->SetupAttachment(Mesh);
}

void ASwordBase::BeginPlay()
{
	Super::BeginPlay();
}

void ASwordBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
