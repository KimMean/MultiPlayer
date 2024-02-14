#include "Components/DamageComponent.h"
#include "Characters/CharacterBase.h"

#include "Utilities/DebugLog.h"

UDamageComponent::UDamageComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UDamageComponent::BeginPlay()
{
	Super::BeginPlay();

}

void UDamageComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDamageComponent::GiveDamage(AActor* Attacker, AActor* Victim, const int32 Damage, const EAttackType Type, const FHitResult& SweepResult)
{
	ACharacterBase* attacker = Cast<ACharacterBase>(Attacker);
	ACharacterBase* victim = Cast<ACharacterBase>(Victim);

	if (attacker == nullptr || victim == nullptr) return;
	if (victim->IsInvincibility() == true) return;

	float totalDamage = Damage;
	if (Type == EAttackType::Physical)
		totalDamage += attacker->GetStatus().Strength;
	else if (Type == EAttackType::Magic)
		totalDamage += attacker->GetStatus().MagicPoint;

	victim->GetDamage(totalDamage, Type, attacker->GetActorLocation(), SweepResult);
}

