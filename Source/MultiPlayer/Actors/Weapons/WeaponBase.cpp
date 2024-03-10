#include "Actors/Weapons/WeaponBase.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"

#include "Utilities/DebugLog.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;
	Tags.Add(TEXT("Weapon"));

	RootComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");

	//Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	SetCollisionEnabled(false);

	Collision->OnComponentBeginOverlap.AddDynamic(this, &AWeaponBase::OnComponentBeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AWeaponBase::OnComponentEndOverlap);

	//Collision->SetCollisionEnabled(ECo)
}

void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::SetSpeed(float InSpeed)
{
	if (!Projectile) return;
	Projectile->SetUpdatedComponent(RootComponent);
	Projectile->InitialSpeed = InSpeed;
	Projectile->MaxSpeed = InSpeed;
}

void AWeaponBase::SetInitialSpeed(float InSpeed)
{
	if (!Projectile) return;
	Projectile->InitialSpeed = InSpeed;
}

void AWeaponBase::SetMaxSpeed(float InSpeed)
{
	if (!Projectile) return;
	Projectile->MaxSpeed = InSpeed;
}

void AWeaponBase::SetDirection(FVector InDirection)
{
	if (!Projectile) return;
	Projectile->Velocity = InDirection * Projectile->InitialSpeed;
}

void AWeaponBase::SetCollisionEnabled(const bool Value)
{
	if (Value == true)
		Collision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	else
		Collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AWeaponBase::SetDamage(int InDamage)
{
	Damage = InDamage;
}

void AWeaponBase::SetSphereRadius(float InRadius)
{
	if (CollisionType != ECollisionType::Sphere) return;
	Cast<USphereComponent>(Collision)->SetSphereRadius(InRadius);
}

void AWeaponBase::SetCapsuleSize(float InRadius, float InHalfHeight)
{
	if (CollisionType != ECollisionType::Capsule) return;
	Cast<UCapsuleComponent>(Collision)->SetCapsuleSize(InRadius, InHalfHeight);
}

void AWeaponBase::SetCapsuleHalfHeight(float InHalfHeight)
{
	if (CollisionType != ECollisionType::Capsule) return;
	Cast<UCapsuleComponent>(Collision)->SetCapsuleHalfHeight(InHalfHeight);
}

void AWeaponBase::SetCapsuleRadius(float InRadius)
{
	if (CollisionType != ECollisionType::Capsule) return;
	Cast<UCapsuleComponent>(Collision)->SetCapsuleRadius(InRadius);
}

void AWeaponBase::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == this) return;
	if (OtherActor == GetOwner()) return;
	if (OtherActor->Tags.Contains("Weapon")) return;

	//DebugLog::Print(OtherActor);
	UGameplayStatics::ApplyDamage(OtherActor, Damage, GetOwner()->GetInstigatorController(), this, UDamageType::StaticClass());
}

void AWeaponBase::OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

