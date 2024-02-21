#include "Characters/AnimInstanceBase.h"
#include "KismetAnimationLibrary.h"

#include "Characters/CharacterBase.h"
#include "Enums/DirectionState.h"
#include "Utilities/DebugLog.h"

UAnimInstanceBase::UAnimInstanceBase()
{
}

void UAnimInstanceBase::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Character = Cast<ACharacterBase>(TryGetPawnOwner());
	if (Character.IsValid() == false)
		return;
}

void UAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Character.IsValid() == false)
		return;

	Direction = UKismetAnimationLibrary::CalculateDirection(Character->GetVelocity(), Character->GetActorRotation());
	Speed = Character->GetVelocity().Size();
}
