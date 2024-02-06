#include "Characters/CharacterBase.h"
#include "CharacterBase.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);


}

void ACharacterBase::SetGenericTeamId(const FGenericTeamId& TeamID)
{
	GenericTeamID = TeamID;
}

FGenericTeamId ACharacterBase::GetGenericTeamId() const
{
	return GenericTeamID;
}
