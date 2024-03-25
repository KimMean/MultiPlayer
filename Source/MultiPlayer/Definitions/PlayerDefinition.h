#pragma once

#include "CoreMinimal.h"

UENUM()
enum class EPlayerClass : uint8
{
	None,
	Warrior,
	Archer,
	Wizard,
	Thief,
};

class MULTIPLAYER_API PlayerDefinition
{
public:
	PlayerDefinition();
	~PlayerDefinition();
};
