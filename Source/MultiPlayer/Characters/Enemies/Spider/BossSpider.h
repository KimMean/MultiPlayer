#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemies/Spider/SpiderBase.h"
#include "BossSpider.generated.h"

UCLASS()
class MULTIPLAYER_API ABossSpider : public ASpiderBase
{
	GENERATED_BODY()

public:
	ABossSpider();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

public :
	virtual void AbilityActivation(ECharacterState InCharacterState) override;

	virtual void MaintainAbility(ECharacterState InCharacterState) override;

private :
	/* Causes an earthquake, damaging enemies within the range. */
	void Ability_EarthQuake();
	/* Deals damage by spitting acid. */
	void SpitOutAcid();
	/* Summons spiders. */
	void SummonSpider();

	void ChargeTowardTargetPosition();


private :
	void CreateWeaponCollider();

protected :
	UPROPERTY(EditAnywhere)
		TSubclassOf<AWeaponBase> Acid;

	FVector TargetLocation;
};
