#include "Characters/Enemies/Spider/BasicSpider/BasicSpider.h"

#include "Actors/Weapons/SphereWeapon.h"

#include "Utilities/DebugLog.h"

ABasicSpider::ABasicSpider()
{
}

void ABasicSpider::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	Weapon = GetWorld()->SpawnActorDeferred<ASphereWeapon>(ASphereWeapon::StaticClass(), GetActorTransform(), this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	Weapon->SetCollisionEnabled(false);
	Weapon->SetCollisionRadius(50);
	Weapon->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	Weapon->SetDamage(5);
	//DebugLog::Print(GetActorLocation());
	FVector currentLocation = GetActorLocation();
	currentLocation.X += 50;
	Weapon->SetActorLocation(currentLocation);
	Weapon->FinishSpawning(Weapon->GetTransform());
	//DebugLog::Print(Weapon->GetActorLocation());

}

void ABasicSpider::BeginPlay()
{
	Super::BeginPlay();
}
