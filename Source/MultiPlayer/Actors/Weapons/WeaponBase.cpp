#include "Actors/Weapons/WeaponBase.h"
#include "Components/StaticMeshComponent.h"

#include "Utilities/DebugLog.h"

AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AWeaponBase::OnBegin);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AWeaponBase::OnEnd);

	//Collision->SetCollisionEnabled(ECo)
}

void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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

void AWeaponBase::OnBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr) return;
	if (OtherActor == this) return;
	if (OtherActor == GetOwner()) return;
}

void AWeaponBase::OnEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

