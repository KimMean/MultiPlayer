#include "Actors/Weapons/CapsuleWeapon.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

ACapsuleWeapon::ACapsuleWeapon()
{
	CollisionType = ECollisionType::Capsule;

	Collision = CreateDefaultSubobject<UCapsuleComponent>("Collision");
	//Mesh = CreateDefaultSubobject<UStaticMeshComponent>("StaticMesh");

	//ConstructorHelpers::FObjectFinder<UStaticMesh> mesh(TEXT("/Script/Engine.StaticMesh'/Game/StarterContent/Shapes/Shape_NarrowCapsule.Shape_NarrowCapsule'"));

	//Cast<UStaticMeshComponent>(Mesh)->SetStaticMesh(mesh.Object);

	//Mesh->SetupAttachment(RootComponent);
	Collision->SetupAttachment(RootComponent);
	//RootComponent = Collision;
	//
	//Mesh->SetupAttachment(RootComponent);
}

void ACapsuleWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void ACapsuleWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
