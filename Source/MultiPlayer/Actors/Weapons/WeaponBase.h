#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enums/AttackType.h"
#include "WeaponBase.generated.h"

class UPrimitiveComponent;
class UStaticMeshComponent;
class UDamageComponent;

UENUM(BlueprintType)
enum class ECollisionType : uint8
{
	Collision,
	Box,
};

UCLASS()
class MULTIPLAYER_API AWeaponBase : public AActor
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UPrimitiveComponent* Collision = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	UStaticMeshComponent* Mesh = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Damage;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EAttackType AttackType;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector AttachOffset = FVector::ZeroVector;

public:	
	AWeaponBase();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	/**
	* @param	Value	true : QueryOnly
	*					false : NoCollision
	*/
	void SetCollisionEnabled(const bool Value);

	void SetDamage(int InDamage);
	void SetAttachOffset(const FVector Value) { AttachOffset = Value; }
	const FVector& GetAttachOffset() const { return AttachOffset; }

public :
	/* Only SphereComponent can be used. */
	virtual void SetCollisionRadius(float InRadius) {}

protected:
	UFUNCTION()
	void OnBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
	void OnEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

};
