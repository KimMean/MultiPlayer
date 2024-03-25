#include "UserInterface/SelectCharacter/CharacterInfo.h"

#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

void UCharacterInfo::NativeConstruct()
{
	Super::NativeConstruct();
	Btn_Select->OnClicked.AddDynamic(this, &UCharacterInfo::Btn_Select_OnClick);
}

void UCharacterInfo::Btn_Select_OnClick()
{
	// ĳ���Ͱ� ���õǾ��ٴ� ���� ��򰡿� �˷��ֱ�
}

void UCharacterInfo::ChangeCharacterInfo(FString InName, int32 InLevel)
{
	Text_Name->SetText(FText::FromString(InName));
	FText level = FText::FromString("Lv : " + FString::FromInt(InLevel));
	Text_Level->SetText(level);

	//Img_Icon->Set
}
