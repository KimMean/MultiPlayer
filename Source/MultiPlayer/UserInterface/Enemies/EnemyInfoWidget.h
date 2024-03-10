#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnemyInfoWidget.generated.h"

class UTextBlock;
class UProgressBar;

UCLASS()
class MULTIPLAYER_API UEnemyInfoWidget : public UUserWidget
{
	GENERATED_BODY()

public :
	virtual void NativeConstruct() override;

public :
	/* Set Enemy Level */
	void SetLevel(int32 InLevel);
	/* Set Enemy Name */
	void SetName(FString InName);
	
	/* Modifies enemy health by percentage. */
	void ModifyHealthPointPercent(float InPercent);
	/* Modifies enemy health to current health and maximum health. */
	void ModifyHealthPointPercent(float InCurValue, float InMaxValue);


protected :
	/* Enemy Level */
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> Text_Level;
	
	/* Enemy Name */
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UTextBlock> Text_Name;

	/* Enemy Hp Percent */
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UProgressBar> PB_HPBar;
};
