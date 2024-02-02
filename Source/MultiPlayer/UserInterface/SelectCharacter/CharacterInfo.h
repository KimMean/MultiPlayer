#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterInfo.generated.h"

class UButton;
class UImage;
class UTextBlock;

UCLASS()
class MULTIPLAYER_API UCharacterInfo : public UUserWidget
{
	GENERATED_BODY()

protected :
	virtual void NativeConstruct() override;

public :
	/* ĳ���� ���� �̺�Ʈ */
	UFUNCTION() void Btn_Select_OnClick();
	
	/* GameInstance���� ĳ���� ������ �ҷ������� �� ������Ʈ �˴ϴ�. */
	void ChangeCharacterInfo(FString InName, int32 InLevel);


private :
	/* ĳ���͸� �����ϴ� ��ư */
	UPROPERTY(meta = (BindWidget)) UButton* Btn_Select;
	/* ĳ������ ������ �˷��ִ� ������ */
	UPROPERTY(meta = (BindWidget)) UImage* Img_Icon;
	/* ĳ������ �г��� */
	UPROPERTY(meta = (BindWidget)) UTextBlock* Text_Name;
	/* ĳ������ ���� */
	UPROPERTY(meta = (BindWidget)) UTextBlock* Text_Level;
};
