#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enums/AttackType.h"
#include "Enums/WeaponType.h"
#include "WeaponBase.generated.h"

class UPrimitiveComponent;
class UMeshComponent;
class UProjectileMovementComponent;


UENUM(BlueprintType)
enum class ECollisionType : uint8
{
	Collision,
	Box,
	Sphere,
	Capsule,
};

UCLASS()
class MULTIPLAYER_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeaponBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	// ~Begin ProjectileMovementComponent
	void SetSpeed(float InSpeed);
	void SetInitialSpeed(float InSpeed);
	void SetMaxSpeed(float InSpeed);
	void SetDirection(FVector InDirection);
	 
	// ~End ProjectileMovementComponent

	/**
	* @param	Value	true : QueryOnly
	*					false : NoCollision
	*/
	void SetCollisionEnabled(const bool Value);

	void SetDamage(int InDamage);

public :
	/* Only SphereComponent can be used. */
	virtual void SetSphereRadius(float InRadius);

	/* Only CapsuleComponent can be used. */
	virtual void SetCapsuleSize(float InRadius, float InHalfHeight);
	virtual void SetCapsuleHalfHeight(float InHalfHeight);
	virtual void SetCapsuleRadius(float InRadius);

protected:
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnComponentEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		UPrimitiveComponent* Collision = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		TObjectPtr<UMeshComponent> Mesh = nullptr;

	UPROPERTY(EditAnywhere)
		TObjectPtr<UProjectileMovementComponent> Projectile = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		int Damage = 10;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		EAttackType AttackType;

	UPROPERTY(VisibleDefaultsOnly)
		EWeaponType WeaponType;

	UPROPERTY(VisibleDefaultsOnly)
		ECollisionType CollisionType;
};
