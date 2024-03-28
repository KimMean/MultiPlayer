#include "Components/StatusComponent.h"

UStatusComponent::UStatusComponent()
{

}


void UStatusComponent::BeginPlay()
{
	Super::BeginPlay();
	SetMaxHealthPoint(CharacterStatus.HealthPoint);
	CurrentHealthPoint = GetMaxHealthPoint();
}

FCharacterStatus& UStatusComponent::GetCharacterStatus()
{
	return CharacterStatus;
}

void UStatusComponent::SetCharacterStatus(FCharacterStatus InCharacterStatus)
{
	CharacterStatus = InCharacterStatus;
}

void UStatusComponent::AdjustCurrentHealthPoint(float InAdjustValue)
{
	CurrentHealthPoint += InAdjustValue;

	if (CurrentHealthPoint >= GetMaxHealthPoint())
		CurrentHealthPoint = GetMaxHealthPoint();

	if (CurrentHealthPoint < 0)
		CurrentHealthPoint = 0;

	if (OnHealthPointChangedDelegate.IsBound())
	{
		OnHealthPointChangedDelegate.Execute();
	}
}

const FString UStatusComponent::GetName()
{
	return CharacterStatus.CharacterName;
}

const int32 UStatusComponent::GetLevel()
{
	return CharacterStatus.Level;
}

const float UStatusComponent::GetExperience()
{
	return CharacterStatus.Experience;
}

const int32 UStatusComponent::GetMaxHealthPoint()
{
	return CharacterStatus.HealthPoint;
}

const int32 UStatusComponent::GetCurrentHealthPoint()
{
	return CurrentHealthPoint;
}

const int32 UStatusComponent::GetMaxMagicPoint()
{
	return CharacterStatus.MagicPoint;
}

const int32 UStatusComponent::GetCurrentMagicPoint()
{
	return CurrentMagicPoint;
}

const int32 UStatusComponent::GetStrength()
{
	return CharacterStatus.Strength;
}

const int32 UStatusComponent::GetIntelligence()
{
	return CharacterStatus.Intelligence;
}

const int32 UStatusComponent::GetPhysicalDefense()
{
	return CharacterStatus.PhysicalDefense;
}

const int32 UStatusComponent::GetMagicDefense()
{
	return CharacterStatus.MagicDefense;
}

void UStatusComponent::SetName(FString InCharacterName)
{
	CharacterStatus.CharacterName = InCharacterName;
}

void UStatusComponent::SetLevel(int32 InCharacterLevel)
{
	CharacterStatus.Level = InCharacterLevel;
}

void UStatusComponent::SetExperience(float InCharacterExperience)
{
	CharacterStatus.Experience = InCharacterExperience;
}

void UStatusComponent::SetMaxHealthPoint(int32 InCharacterHealthPoint)
{
	CharacterStatus.HealthPoint = InCharacterHealthPoint;
}

void UStatusComponent::SetCurrentHealthPoint(int32 InCharacterHealthPoint)
{
	CurrentHealthPoint = InCharacterHealthPoint;
}

void UStatusComponent::SetMaxMagicPoint(int32 InCharacterMagicPoint)
{
	CharacterStatus.MagicPoint = InCharacterMagicPoint;
}

void UStatusComponent::SetCurrentMagicPoint(int32 InCharacterMagicPoint)
{
	CurrentMagicPoint = InCharacterMagicPoint;
}

void UStatusComponent::SetStrength(int32 InCharacterStrength)
{
	CharacterStatus.Strength = InCharacterStrength;
}

void UStatusComponent::SetIntelligence(int32 InCharacterIntelligence)
{
	CharacterStatus.Intelligence = InCharacterIntelligence;
}

void UStatusComponent::SetPhysicalDefense(int32 InCharacterPhysicalDefense)
{
	CharacterStatus.PhysicalDefense = InCharacterPhysicalDefense;
}

void UStatusComponent::SetMagicDefense(int32 InCharacterMagicDefense)
{
	CharacterStatus.MagicDefense = InCharacterMagicDefense;
}



