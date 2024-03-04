#include "Characters/Enemies/Spider/BossSpider.h"

#include "Kismet/GameplayStatics.h"
#include "Engine/SkeletalMeshSocket.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

#include "GameSetting/Controllers/AIControllerBase.h"
#include "Actors/Weapons/CapsuleWeapon.h"
#include "Actors/Weapons/CapsuleWeapon.h"
#include "Characters/PlayerCharacter/PlayerBase.h"

#include "Utilities/DebugLog.h"
#include "Utilities/UsefulMath.h"

ABossSpider::ABossSpider()
{
	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(L"/Script/Engine.SkeletalMesh'/Game/InfinityBladeAdversaries/Enemy/Enemy_Great_Spider/SK_Greater_Spider.SK_Greater_Spider'");
	GetMesh()->SetSkeletalMesh(mesh.Object);

	//Weapons[EWeaponType::LeftFoot] = CreateDefaultSubobject<ACapsuleWeapon>("CollisionWeapon");

	GetCapsuleComponent()->SetCapsuleHalfHeight(120);
	GetCapsuleComponent()->SetCapsuleRadius(120);

	GetMesh()->SetRelativeLocation(FVector(0, 0, -120));
}

void ABossSpider::BeginPlay()
{
	Super::BeginPlay();

	CreateWeaponCollider();
	SetActionRange(300.0f);
}

void ABossSpider::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void ABossSpider::AbilityActivation(ECharacterState InCharacterState)
{
	Super::AbilityActivation(InCharacterState);

	switch (InCharacterState)
	{
	case ECharacterState::Defend:
		Ability_EarthQuake();
		break;
	case ECharacterState::Hold:
		SummonSpider();
		break;
	case ECharacterState::Chase:
		TargetLocation = Cast<AAIControllerBase>(GetController())->GetTargetActor()->GetActorLocation();
		break;
	default:
		break;
	}
}

void ABossSpider::MaintainAbility(ECharacterState InCharacterState)
{
	Super::MaintainAbility(InCharacterState);

	switch (InCharacterState)
	{
	case ECharacterState::Cast:
		SpitOutAcid();
		break;
	case ECharacterState::Chase :
		ChargeTowardTargetPosition();
		break;
	default:
		break;
	}
}

void ABossSpider::Ability_EarthQuake()
{
	float radialDamage = 10.0f;
	float radius = 500.0f;
	TArray<AActor*> ignoreActors;


	FVector location = GetMesh()->GetSocketByName("BackWeapon")->GetSocketLocation(GetMesh());
	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes = { UEngineTypes::ConvertToObjectType(ECollisionChannel::ECC_Pawn) };

	UKismetSystemLibrary::SphereOverlapActors(GetWorld(), location, radius, ObjectTypes, APlayerBase::StaticClass(), ignoreActors, ignoreActors);

	UGameplayStatics::ApplyRadialDamage(GetWorld(), radialDamage, location, radius, UDamageType::StaticClass(), ignoreActors, this, GetInstigatorController());
}

void ABossSpider::SpitOutAcid()
{
	if (!Acid) return;

	AActor* actor = Cast<AAIControllerBase>(GetController())->GetTargetActor();
	if (!actor) return;

	//const USkeletalMeshSocket* socket =
	FTransform transform = GetMesh()->GetSocketTransform("HeadWeapon");
	
	TObjectPtr<AWeaponBase> weapon = GetWorld()->SpawnActorDeferred<AWeaponBase>(Acid, transform, this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	weapon->SetSpeed(1000.0f);
	weapon->FinishSpawning(transform);

	FVector location = UsefulMath::GetRandomLocationWithinRange(actor->GetActorLocation(), 500.0f);
	//FVector direction = actor->GetActorLocation() - transform.GetLocation();
	FVector direction = location - transform.GetLocation();
	direction = (direction.GetSafeNormal() + GetActorUpVector() * 2.0f) * 0.5f;
	weapon->SetDirection(direction);
}

void ABossSpider::SummonSpider()
{
}

void ABossSpider::ChargeTowardTargetPosition()
{
	// TargetLocation 으로 이동
	FVector direction = TargetLocation - GetActorLocation();
	FVector moveDelta = direction.GetSafeNormal() * GetCharacterMovement()->GetMaxSpeed() * 2.0f * GetWorld()->GetDeltaSeconds();
	SetActorLocation(GetActorLocation() + moveDelta);


}

void ABossSpider::CreateWeaponCollider()
{
	TObjectPtr<UClass> capsule = ACapsuleWeapon::StaticClass();

	// LeftWeapon
	const USkeletalMeshSocket* socket = GetMesh()->GetSocketByName("LeftWeapon");
	FTransform transform = socket->GetSocketTransform(GetMesh());

	TObjectPtr<AWeaponBase> weapon = GetWorld()->SpawnActorDeferred<AWeaponBase>(capsule, transform, this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	socket->AttachActor(weapon, GetMesh());
	weapon->SetCapsuleSize(20, 80);
	weapon->FinishSpawning(transform);
	Weapons.Add(EWeaponType::LeftHand, weapon);


	socket = GetMesh()->GetSocketByName("RightWeapon");
	transform = socket->GetSocketTransform(GetMesh());

	weapon = GetWorld()->SpawnActorDeferred<AWeaponBase>(capsule, transform, this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	socket->AttachActor(weapon, GetMesh());
	weapon->SetCapsuleSize(20, 80);
	weapon->FinishSpawning(transform);
	Weapons.Add(EWeaponType::RightHand, weapon);


	//TObjectPtr<UClass> Sphere = ASphereWeapon::StaticClass();
	//
	//socket = GetMesh()->GetSocketByName("BackWeapon");
	//transform = socket->GetSocketTransform(GetMesh());
	//
	//weapon = GetWorld()->SpawnActorDeferred<AWeaponBase>(Sphere, transform, this, this, //ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	//socket->AttachActor(weapon, GetMesh());
	//weapon->SetSphereRadius(200);
	//weapon->FinishSpawning(transform);
	//Weapons.Add(EWeaponType::Tail, weapon);
}
