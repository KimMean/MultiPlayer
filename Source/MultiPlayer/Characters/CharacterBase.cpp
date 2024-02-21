#include "Characters/CharacterBase.h"
#include "Kismet/KismetMathLibrary.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "Utilities/DebugLog.h"

ACharacterBase::ACharacterBase()
{
	SetGenericTeamId(1);
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}


void ACharacterBase::SetCharacterState(ECharacterState InState)
{
	ECharacterState type = CharacterState;
	CharacterState = InState;

	if (OnCharacterStateTypeChanged.IsBound())
	{
		OnCharacterStateTypeChanged.Broadcast(type, CharacterState);
	}
}

void ACharacterBase::SetGenericTeamId(const FGenericTeamId& TeamID)
{
	GenericTeamID = TeamID;
}

FGenericTeamId ACharacterBase::GetGenericTeamId() const
{
	return GenericTeamID;
}
