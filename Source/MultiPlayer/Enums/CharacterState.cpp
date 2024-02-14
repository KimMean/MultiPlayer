#include "Enums/CharacterState.h"
#include "Utilities/DebugLog.h"

UCharacterState::UCharacterState()
{

}

FString UCharacterState::ToString(ECharacterState Value)
{
	FString str = L"";

	switch (Value)
	{
	case ECharacterState::Idle:
		str = L"Idle";
		break;
	case ECharacterState::Move:
		str = L"Move";
		break;
	case ECharacterState::Attack:
		str = L"Attack";
		break;
	case ECharacterState::Smash:
		str = L"Smash";
		break;
	case ECharacterState::Hit:
		str = L"Hit";
		break;
	case ECharacterState::Evation:
		str = L"Evation";
		break;
	case ECharacterState::Death:
		str = L"Death";
		break;
	default:
		break;
	}

	return str;
}

void UCharacterState::PrintString(ECharacterState Value, float Time, FColor Color)
{
	FString str = L"";
	str = L"Character State : " + UCharacterState::ToString(Value);
	DebugLog::Print(str, -1, Time, Color);
}
