#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/SlateEnums.h"
#include "Definitions/PlayerDefinition.h"
#include "WCreateCharacter.generated.h"

class UButton;
class UTextBlock;
class UEditableTextBox;

UCLASS()
class MULTIPLAYER_API UWCreateCharacter : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public :
	UFUNCTION() void OnClick_Btn_Warrior();
	UFUNCTION() void OnClick_Btn_Archer();
	UFUNCTION() void OnClick_Btn_Wizard();
	UFUNCTION() void OnClick_Btn_Thief();

	UFUNCTION() void OnClick_Btn_Verify();
	UFUNCTION() void OnClick_Btn_Back();

protected :
	UPROPERTY(meta = (BindWidget)) TObjectPtr<UButton> Btn_Warrior;
	UPROPERTY(meta = (BindWidget)) TObjectPtr<UButton> Btn_Archer;
	UPROPERTY(meta = (BindWidget)) TObjectPtr<UButton> Btn_Wizard;
	UPROPERTY(meta = (BindWidget)) TObjectPtr<UButton> Btn_Thief;

	UPROPERTY(meta = (BindWidget)) TObjectPtr<UButton> Btn_Verify;
	UPROPERTY(meta = (BindWidget)) TObjectPtr<UButton> Btn_Back;

	UPROPERTY(meta = (BindWidget)) TObjectPtr<UTextBlock> Text_Class;
	UPROPERTY(meta = (BindWidget)) TObjectPtr<UTextBlock> Text_ClassDiscription;

	UPROPERTY(meta = (BindWidget)) TObjectPtr<UEditableTextBox> TB_Name;


	EPlayerClass PlayerClass = EPlayerClass::None;

protected :
	/* DataTable을 참조합니다. */
	TObjectPtr<UDataTable> DT_CharacterBaseStatus;
};
