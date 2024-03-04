// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WeaponType.generated.h"

UENUM(BlueprintType)
enum class EWeaponType : uint8
{
	None,
	Head,
	Body,
	Tail,
	Tooth,
	LeftHand,
	RightHand,
	TwoHand,
	LeftFoot,
	RightFoot,
	TwoFeet,
	OneHandSword,
	TwoHandSword,
};

class MULTIPLAYER_API WeaponType
{
public:
	WeaponType();
	~WeaponType();
};
