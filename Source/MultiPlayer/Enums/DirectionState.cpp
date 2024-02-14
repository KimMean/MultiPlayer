#include "Enums/DirectionState.h"
#include "Utilities/DebugLog.h"

UDirectionState::UDirectionState()
{
}

FString UDirectionState::ToString(EDirectionState Value)
{
	FString str;
	switch (Value)
	{
	case EDirectionState::None:
		str = L"None";
		break;
	case EDirectionState::Front:
		str = L"Front";
		break;
	case EDirectionState::Back:
		str = L"Back";
		break;
	case EDirectionState::Left:
		str = L"Left";
		break;
	case EDirectionState::Right:
		str = L"Right";
		break;
	case EDirectionState::FrontLeft:
		str = L"FrontLeft";
		break;
	case EDirectionState::FrontRight:
		str = L"FrontRight";
		break;
	case EDirectionState::BackLeft:
		str = L"BackLeft";
		break;
	case EDirectionState::BackRight:
		str = L"BackRight";
		break;
	case EDirectionState::Up:
		str = L"Up";
		break;
	case EDirectionState::Down:
		str = L"Down";
		break;
	default:
		break;
	}
	return str;
}

void UDirectionState::PrintString(EDirectionState Value, float Time, FColor Color)
{
	FString str;
	str = L"Direction State : " + UDirectionState::ToString(Value);

	DebugLog::Print(str, -1, Time, Color);
}
