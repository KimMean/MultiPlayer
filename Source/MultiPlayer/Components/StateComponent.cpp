

#include "Components/StateComponent.h"

UStateComponent::UStateComponent()
{
}


// Called when the game starts
void UStateComponent::BeginPlay()
{
	Super::BeginPlay();
	
}

bool UStateComponent::GetIsIdleMode()
{
	return CheckCharacterState(ECharacterState::Idle);
}

bool UStateComponent::GetIsWaitMode()
{
	return CheckCharacterState(ECharacterState::Wait);
}

bool UStateComponent::GetIsMoveMode()
{
	return CheckCharacterState(ECharacterState::Move);
}

bool UStateComponent::GetIsAttackMode()
{
	return CheckCharacterState(ECharacterState::Attack);
}

bool UStateComponent::GetIsDefendMode()
{
	return CheckCharacterState(ECharacterState::Defend);
}

bool UStateComponent::GetIsPatrolMode()
{
	return CheckCharacterState(ECharacterState::Patrol);
}

bool UStateComponent::GetIsChaseMode()
{
	return CheckCharacterState(ECharacterState::Chase);
}

bool UStateComponent::GetIsHoldMode()
{
	return CheckCharacterState(ECharacterState::Hold);
}

bool UStateComponent::GetIsHitMode()
{
	return CheckCharacterState(ECharacterState::Hit);
}

bool UStateComponent::GetIsEvationMode()
{
	return CheckCharacterState(ECharacterState::Evation);
}

bool UStateComponent::GetIsDeathMode()
{
	return CheckCharacterState(ECharacterState::Death);
}

void UStateComponent::SetIdleMode()
{
	SetCharacterState(ECharacterState::Idle);
}

void UStateComponent::SetWaitMode()
{
	SetCharacterState(ECharacterState::Wait);
}

void UStateComponent::SetMoveMode()
{
	SetCharacterState(ECharacterState::Move);
}

void UStateComponent::SetAttackMode()
{
	SetCharacterState(ECharacterState::Attack);
}

void UStateComponent::SetDefendMode()
{
	SetCharacterState(ECharacterState::Defend);
}

void UStateComponent::SetPatrolMode()
{
	SetCharacterState(ECharacterState::Patrol);	
}

void UStateComponent::SetChaseMode()
{
	SetCharacterState(ECharacterState::Chase);
}

void UStateComponent::SetHoldMode()
{
	SetCharacterState(ECharacterState::Hold);
}

void UStateComponent::SetHitMode()
{
	SetCharacterState(ECharacterState::Hit);
}

void UStateComponent::SetEvationMode()
{
	SetCharacterState(ECharacterState::Evation);
}

void UStateComponent::SetDeathMode()
{
	SetCharacterState(ECharacterState::Death);
}

const ECharacterState UStateComponent::GetCharacterState()
{
	return CharacterState;
}

void UStateComponent::SetCharacterState(ECharacterState InState)
{
	if (CharacterState == InState) return;
	if (CharacterState == ECharacterState::Death) return;

	ECharacterState prevState = CharacterState;
	CharacterState = InState;

	if (CharacterStateChangedDelegate.IsBound())
	{
		CharacterStateChangedDelegate.Broadcast(prevState, CharacterState);
	}
}

bool UStateComponent::CheckCharacterState(ECharacterState InState)
{
	return CharacterState == InState;
}

