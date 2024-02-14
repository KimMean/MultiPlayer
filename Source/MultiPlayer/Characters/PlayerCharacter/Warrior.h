// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/PlayerCharacter/PlayerBase.h"
#include "Warrior.generated.h"

/**
 * 
 */
UCLASS()
class MULTIPLAYER_API AWarrior : public APlayerBase
{
	GENERATED_BODY()

public:
	AWarrior();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

protected:
	virtual void OnAttacking() {}
	virtual void OnSmashing() {}

};
