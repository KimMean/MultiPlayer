#include "Characters/CharacterBase.h"

#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Components/StateComponent.h"
#include "Components/AnimationComponent.h"

#include "Utilities/DebugLog.h"

ACharacterBase::ACharacterBase()
{
	SetGenericTeamId(1);

	Animation = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
	CharacterState = CreateDefaultSubobject<UStateComponent>(TEXT("StateComponent"));
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	CharacterState->CharacterStateChangedDelegate.AddDynamic(this, &ACharacterBase::OnCharacterStateChanged);
}

void ACharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}


//void ACharacterBase::SetCharacterState(ECharacterState InState)
//{
//	ECharacterState type = CharacterState;
//	CharacterState = InState;
//
//	if (OnCharacterStateTypeChanged.IsBound())
//	{
//		OnCharacterStateTypeChanged.Broadcast(type, CharacterState);
//	}
//}

const TObjectPtr<UStateComponent> ACharacterBase::GetCharacterStateComponent() const
{
	return CharacterState;
}

UAnimationComponent* ACharacterBase::GetAnimationComponent()
{
	return Animation;
}

void ACharacterBase::SetGenericTeamId(const FGenericTeamId& TeamID)
{
	GenericTeamID = TeamID;
}

FGenericTeamId ACharacterBase::GetGenericTeamId() const
{
	return GenericTeamID;
}

void ACharacterBase::OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState)
{
	//DebugLog::Print(InNewState) 
	DebugLog::Print(UCharacterState::ToString(InNewState));
}
