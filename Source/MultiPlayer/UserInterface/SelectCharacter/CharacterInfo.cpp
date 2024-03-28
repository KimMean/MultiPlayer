#include "UserInterface/SelectCharacter/CharacterInfo.h"

#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"

#include "GameSetting/GameMode/GameMode_SelectCharacter.h"

#include "Utilities/DebugLog.h"

void UCharacterInfo::NativeConstruct()
{
	Super::NativeConstruct();
	Btn_Select->OnClicked.AddDynamic(this, &UCharacterInfo::Btn_Select_OnClick);
}

void UCharacterInfo::Btn_Select_OnClick()
{
	// 캐릭터가 선택되었다는 것을 어딘가에 알려주기
	Cast<AGameMode_SelectCharacter>(UGameplayStatics::GetGameMode(GetWorld()))->SelectCharacter(PlayerSlotIndex);
}

void UCharacterInfo::ChangeCharacterInfo(FString InName, int32 InLevel)
{
	Text_Name->SetText(FText::FromString(InName));
	FText level = FText::FromString("Lv : " + FString::FromInt(InLevel));
	Text_Level->SetText(level);

	//Img_Icon->Set
}
