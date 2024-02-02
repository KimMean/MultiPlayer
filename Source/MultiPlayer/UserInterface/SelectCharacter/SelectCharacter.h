#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SelectCharacter.generated.h"

class UUserWidget;
class UWidgetSwitcher;
class UButton;


UCLASS()
class MULTIPLAYER_API USelectCharacter : public UUserWidget
{
	GENERATED_BODY()

protected :
	virtual void NativeConstruct() override;


public :
	UFUNCTION() void CreateCharacter_OnClick();





private :
	TArray<UWidgetSwitcher*> WS_Selects;

	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_0;
	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_1;
	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_2;
	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_3;
	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_4;

	UPROPERTY(meta = (BindWidget)) UUserWidget* WB_CreateCharacter_0;
	UPROPERTY(meta = (BindWidget)) UUserWidget* WB_CreateCharacter_1;
	UPROPERTY(meta = (BindWidget)) UUserWidget* WB_CreateCharacter_2;
	UPROPERTY(meta = (BindWidget)) UUserWidget* WB_CreateCharacter_3;
	UPROPERTY(meta = (BindWidget)) UUserWidget* WB_CreateCharacter_4;
};
