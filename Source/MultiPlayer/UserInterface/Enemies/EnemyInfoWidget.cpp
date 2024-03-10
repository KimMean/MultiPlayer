#include "UserInterface/Enemies/EnemyInfoWidget.h"

#include "Components/TextBlock.h"
#include "Components/ProgressBar.h"

#include "Utilities/DebugLog.h"


void UEnemyInfoWidget::NativeConstruct()
{
	Super::NativeConstruct();
	Text_Level = Cast<UTextBlock>(GetWidgetFromName(TEXT("Text_Level")));
}

void UEnemyInfoWidget::SetLevel(int32 InLevel)
{
	Text_Level->SetText(FText::FromString(FString::FromInt(InLevel)));
}

void UEnemyInfoWidget::SetName(FString InName)
{
	Text_Name->SetText(FText::FromString(InName));
}

void UEnemyInfoWidget::ModifyHealthPointPercent(float InPercent)
{
	PB_HPBar->SetPercent(InPercent);
}

void UEnemyInfoWidget::ModifyHealthPointPercent(float InCurValue, float InMaxValue)
{
	PB_HPBar->SetPercent(InCurValue / InMaxValue);
}
