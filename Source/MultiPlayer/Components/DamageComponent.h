#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Enums/AttackType.h"
#include "DamageComponent.generated.h"

class ACharacterBase;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYER_API UDamageComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UDamageComponent();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	void GiveDamage(AActor* Attacker, AActor* Victim, const int32 Damage, const EAttackType Type, const FHitResult& SweepResult);
};
