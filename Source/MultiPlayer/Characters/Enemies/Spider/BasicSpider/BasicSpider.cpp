#include "Characters/Enemies/Spider/BasicSpider/BasicSpider.h"

#include "Components/CapsuleComponent.h"
#include "Actors/Weapons/SphereWeapon.h"

#include "Utilities/DebugLog.h"

ABasicSpider::ABasicSpider()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(60);
	GetCapsuleComponent()->SetCapsuleRadius(60);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -60));

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"/Script/Engine.SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Spiderling/SK_Spiderling.SK_Spiderling'");
	GetMesh()->SetSkeletalMesh(mesh.Object);
}

void ABasicSpider::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	//Weapon = GetWorld()->SpawnActorDeferred<ASphereWeapon>(ASphereWeapon::StaticClass(), //GetActorTransform(), this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	//Weapon->SetCollisionEnabled(false);
	//Weapon->SetCollisionRadius(50);
	//Weapon->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	//Weapon->SetDamage(5);
	//DebugLog::Print(GetActorLocation());
	//FVector currentLocation = GetActorLocation();
	//currentLocation.X += 50;
	//Weapon->SetActorLocation(currentLocation);
	//Weapon->FinishSpawning(Weapon->GetTransform());
	//DebugLog::Print(Weapon->GetActorLocation());

}

void ABasicSpider::BeginPlay()
{
	Super::BeginPlay();
}

void ABasicSpider::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
