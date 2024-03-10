#include "UserInterface/Player/Player_HealthPoint.h"

#include "Components/ProgressBar.h"

void UPlayer_HealthPoint::NativeConstruct()
{
	Super::NativeConstruct();
}

void UPlayer_HealthPoint::ModifyHealthPointPercent(float InPercent)
{
	PB_HealthPoint->SetPercent(InPercent);
}

void UPlayer_HealthPoint::ModifyHealthPointPercent(float InCurValue, float InMaxValue)
{
	PB_HealthPoint->SetPercent(InCurValue / InMaxValue);
}
