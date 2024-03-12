#include "Characters/Enemies/Spider/BasicSpider.h"

#include "Engine/SkeletalMeshSocket.h"
#include "Components/CapsuleComponent.h"
#include "Actors/Weapons/SphereWeapon.h"

#include "Utilities/DebugLog.h"

ABasicSpider::ABasicSpider()
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(90);
	GetCapsuleComponent()->SetCapsuleRadius(60);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -90));

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"/Script/Engine.SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Spiderling/SK_Spiderling.SK_Spiderling'");
	GetMesh()->SetSkeletalMesh(mesh.Object);
}

void ABasicSpider::BeginPlay()
{
	Super::BeginPlay();
	CreateWeaponCollider();
}

void ABasicSpider::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABasicSpider::CreateWeaponCollider()
{
	TObjectPtr<UClass> sphere = ASphereWeapon::StaticClass();

	// HeadWeapon
	const USkeletalMeshSocket* socket = GetMesh()->GetSocketByName("HeadWeapon");
	FTransform transform = socket->GetSocketTransform(GetMesh());

	TObjectPtr<AWeaponBase> weapon = GetWorld()->SpawnActorDeferred<AWeaponBase>(sphere, transform, this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	socket->AttachActor(weapon, GetMesh());
	weapon->SetSphereRadius(50);
	weapon->FinishSpawning(transform);
	Weapons.Add(EWeaponType::Head, weapon);
}
