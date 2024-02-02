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
	/* 캐릭터 선택 이벤트 */
	UFUNCTION() void Btn_Select_OnClick();
	
	/* GameInstance에서 캐릭터 정보가 불러와졌을 때 업데이트 됩니다. */
	void ChangeCharacterInfo(FString InName, int32 InLevel);


private :
	/* 캐릭터를 선택하는 버튼 */
	UPROPERTY(meta = (BindWidget)) UButton* Btn_Select;
	/* 캐릭터의 직업을 알려주는 아이콘 */
	UPROPERTY(meta = (BindWidget)) UImage* Img_Icon;
	/* 캐릭터의 닉네임 */
	UPROPERTY(meta = (BindWidget)) UTextBlock* Text_Name;
	/* 캐릭터의 레벨 */
	UPROPERTY(meta = (BindWidget)) UTextBlock* Text_Level;
};
