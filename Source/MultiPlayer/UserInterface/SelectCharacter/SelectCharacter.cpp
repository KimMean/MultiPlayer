#include "UserInterface/SelectCharacter/SelectCharacter.h"

#include "Kismet/GameplayStatics.h"
#include "Components/WidgetSwitcher.h"
#include "Components/MultilineEditableTextBox.h"

#include "GameSetting/GameMode/GameMode_SelectCharacter.h"
#include "Characters/CharacterInformation.h"
#include "Definitions/PlayerDefinition.h"
#include "UserInterface/SelectCharacter/CharacterInfo.h"
#include "UserInterface/SelectCharacter/CreateCharacter.h"

#include "Utilities/DebugLog.h"

void USelectCharacter::NativeConstruct()
{
	Super::NativeConstruct();

	WS_Selects.Add(WS_Select_0);
	WS_Selects.Add(WS_Select_1);
	WS_Selects.Add(WS_Select_2);
	WS_Selects.Add(WS_Select_3);
	WS_Selects.Add(WS_Select_4);

	WS_Select_0->SetActiveWidgetIndex(1);
	CharacterInfomations.Add(WB_CharacterInfo_0);
	CharacterInfomations.Add(WB_CharacterInfo_1);
	CharacterInfomations.Add(WB_CharacterInfo_2);
	CharacterInfomations.Add(WB_CharacterInfo_3);
	CharacterInfomations.Add(WB_CharacterInfo_4);

	for (int32 i = 0; i < WS_Selects.Num(); i++)
	{
		AGameMode_SelectCharacter* gameMode = Cast<AGameMode_SelectCharacter>(UGameplayStatics::GetGameMode(GetWorld()));
		if (gameMode->ContainsPlayerData(i))
		{
			FCharacterStatus status = gameMode->GetPlayerStatus(i);
			WS_Selects[i]->SetActiveWidgetIndex(1);
			CharacterInfomations[i]->ChangeCharacterInfo(status.CharacterName, status.Level);
		}
	}

	for (int32 i = 0; i < WS_Selects.Num(); i++)
	{
		if (WS_Selects[i]->GetActiveWidgetIndex() == 1)
		{
			Cast<AGameMode_SelectCharacter>(UGameplayStatics::GetGameMode(GetWorld()))->SelectCharacter(i);
			break;
		}
	}
}

void USelectCharacter::ShowCharacterInformation(EPlayerClass InClass, FCharacterStatus InStatus)
{
	FString str;
	str.Append("Level : " + FString::FromInt(InStatus.Level) + "\n");

	const UEnum* ClassEnum = FindObject<UEnum>(ANY_PACKAGE, TEXT("EPlayerClass"), true);
	if (ClassEnum)
	{
		FString className = ClassEnum->GetNameStringByValue((int64)InClass);
		str.Append("Class : " + className);
	}
	MLTB_Info->SetText(FText::FromString(str));
}

void USelectCharacter::StartButton_OnClicked()
{
}

void USelectCharacter::DeleteButton_OnClicked()
{
}
