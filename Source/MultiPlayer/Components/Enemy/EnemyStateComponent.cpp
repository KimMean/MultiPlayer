#include "Components/Enemy/EnemyStateComponent.h"

UEnemyStateComponent::UEnemyStateComponent()
{
	//PrimaryComponentTick.bCanEverTick = true;

}


// Called when the game starts
void UEnemyStateComponent::BeginPlay()
{
	Super::BeginPlay();

}


//void UEnemyStateComponent::TickComponent(float DeltaTime, ELevelTick TickType, //FActorComponentTickFunction* ThisTickFunction)
//{
//	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
//
//}

void UEnemyStateComponent::SetIdleMode()
{
	ChangeType(EEnemyStateType::Idle);
}

void UEnemyStateComponent::SetPatrolMode()
{
	ChangeType(EEnemyStateType::Patrol);
}

void UEnemyStateComponent::SetWaitMode()
{
	ChangeType(EEnemyStateType::Wait);
}

void UEnemyStateComponent::SetActionMode()
{
	ChangeType(EEnemyStateType::Action);
}

void UEnemyStateComponent::SetChaseMode()
{
	ChangeType(EEnemyStateType::Chase);
}

void UEnemyStateComponent::SetRetreatMode()
{
	ChangeType(EEnemyStateType::Retreat);
}

void UEnemyStateComponent::SetDefendMode()
{
	ChangeType(EEnemyStateType::Defend);
}

void UEnemyStateComponent::SetEvadeMode()
{
	ChangeType(EEnemyStateType::Evade);
}

void UEnemyStateComponent::SetHittedMode()
{
	ChangeType(EEnemyStateType::Hitted);
}

void UEnemyStateComponent::SetDeathMode()
{
	ChangeType(EEnemyStateType::Death);
}

void UEnemyStateComponent::ChangeType(EEnemyStateType InType)
{
	EEnemyStateType type = Type;
	Type = InType;

	if (OnEnemyStateTypeChanged.IsBound())
	{
		OnEnemyStateTypeChanged.Broadcast(type, Type);
	}
}
