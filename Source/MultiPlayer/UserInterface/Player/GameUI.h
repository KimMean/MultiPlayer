#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameUI.generated.h"

class UPlayer_HealthPoint;

UCLASS()
class MULTIPLAYER_API UGameUI : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

public:
	/* Modifies health by percentage. */
	void ModifyHealthPointPercent(float InPercent);
	/* Modifies health to current health and maximum health. */
	void ModifyHealthPointPercent(float InCurValue, float InMaxValue);

protected :
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UPlayer_HealthPoint> WB_Player_HP;
};
