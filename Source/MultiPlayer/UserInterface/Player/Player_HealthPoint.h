#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Player_HealthPoint.generated.h"

class UProgressBar;

UCLASS()
class MULTIPLAYER_API UPlayer_HealthPoint : public UUserWidget
{
	GENERATED_BODY()
	
public :
	virtual void NativeConstruct() override;

public :
	/* Modifies health by percentage. */
	void ModifyHealthPointPercent(float InPercent);
	/* Modifies health to current health and maximum health. */
	void ModifyHealthPointPercent(float InCurValue, float InMaxValue);

protected :
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UProgressBar> PB_HealthPoint;
};
