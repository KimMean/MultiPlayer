// Copyright Epic Games, Inc. All Rights Reserved.

#include "MultiPlayerGameMode.h"
#include "MultiPlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMultiPlayerGameMode::AMultiPlayerGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'///Game/Characters/BP_Manny.BP_Manny_C'"));
	//
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
}
