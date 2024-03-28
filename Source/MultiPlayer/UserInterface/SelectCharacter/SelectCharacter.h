#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Definitions/PlayerDefinition.h"
#include "Characters/CharacterInformation.h"
#include "SelectCharacter.generated.h"

class UUserWidget;
class UButton;
class UMultiLineEditableTextBox;
class UWidgetSwitcher;
class UCreateCharacter;
class UCharacterInfo;


UCLASS()
class MULTIPLAYER_API USelectCharacter : public UUserWidget
{
	GENERATED_BODY()

protected :
	virtual void NativeConstruct() override;

public :
	void ShowCharacterInformation(EPlayerClass InClass, FCharacterStatus InStatus);

	UFUNCTION() void StartButton_OnClicked();
	UFUNCTION() void DeleteButton_OnClicked();

protected :
	TArray<UWidgetSwitcher*> WS_Selects;
	TArray<UCharacterInfo*> CharacterInfomations;

	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_0;
	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_1;
	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_2;
	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_3;
	UPROPERTY(meta = (BindWidget)) UWidgetSwitcher* WS_Select_4;

	UPROPERTY(meta = (BindWidget)) UCreateCharacter* WB_CreateCharacter_0;
	UPROPERTY(meta = (BindWidget)) UCreateCharacter* WB_CreateCharacter_1;
	UPROPERTY(meta = (BindWidget)) UCreateCharacter* WB_CreateCharacter_2;
	UPROPERTY(meta = (BindWidget)) UCreateCharacter* WB_CreateCharacter_3;
	UPROPERTY(meta = (BindWidget)) UCreateCharacter* WB_CreateCharacter_4;

	UPROPERTY(meta = (BindWidget)) UCharacterInfo* WB_CharacterInfo_0;
	UPROPERTY(meta = (BindWidget)) UCharacterInfo* WB_CharacterInfo_1;
	UPROPERTY(meta = (BindWidget)) UCharacterInfo* WB_CharacterInfo_2;
	UPROPERTY(meta = (BindWidget)) UCharacterInfo* WB_CharacterInfo_3;
	UPROPERTY(meta = (BindWidget)) UCharacterInfo* WB_CharacterInfo_4;

	UPROPERTY(meta = (BindWidget)) UMultiLineEditableTextBox* MLTB_Info;

	UPROPERTY(meta = (BindWidget)) UButton* Btn_Start;
	UPROPERTY(meta = (BindWidget)) UButton* Btn_Delete;
	
};
