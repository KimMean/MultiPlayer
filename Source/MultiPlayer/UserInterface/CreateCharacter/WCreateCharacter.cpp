#include "UserInterface/CreateCharacter/WCreateCharacter.h"

#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/EditableTextBox.h"

#include "System/DataSystem/SaveSystem.h"
#include "LevelScripts/LevelScript_CreateCharacter.h"

#include "Utilities/DebugLog.h"

void UWCreateCharacter::NativeConstruct()
{
	Super::NativeConstruct();

	Btn_Warrior->OnClicked.AddDynamic(this, &UWCreateCharacter::OnClick_Btn_Warrior);
	Btn_Archer->OnClicked.AddDynamic(this, &UWCreateCharacter::OnClick_Btn_Archer);
	Btn_Wizard->OnClicked.AddDynamic(this, &UWCreateCharacter::OnClick_Btn_Wizard);
	Btn_Thief->OnClicked.AddDynamic(this, &UWCreateCharacter::OnClick_Btn_Thief);

	Btn_Verify->OnClicked.AddDynamic(this, &UWCreateCharacter::OnClick_Btn_Verify);
	Btn_Back->OnClicked.AddDynamic(this, &UWCreateCharacter::OnClick_Btn_Back);

	//TB_Name->OnTextCommitted.AddDynamic(this, &UWCreateCharacter::OnTextCommitted_Nickname);
}

void UWCreateCharacter::OnClick_Btn_Warrior()
{
	//Cast<ALevelScript_CreateCharacter>(GetWorld()->GetLevelScriptActor())
	PlayerClass = EPlayerClass::Warrior;
}

void UWCreateCharacter::OnClick_Btn_Archer()
{
	PlayerClass = EPlayerClass::Archer;
}

void UWCreateCharacter::OnClick_Btn_Wizard()
{
	PlayerClass = EPlayerClass::Wizard;
}

void UWCreateCharacter::OnClick_Btn_Thief()
{
	PlayerClass = EPlayerClass::Thief;
}

void UWCreateCharacter::OnClick_Btn_Verify()
{
	if (PlayerClass == EPlayerClass::None) return;

	FString nickname = TB_Name->GetText().ToString();
	if (nickname.IsEmpty()) return;
	if (nickname.Len() > 16) 
	{
		DebugLog::Print("Nickname is long");
		return;
	}
	if (USaveSystem* SaveGameInstance = Cast<USaveSystem>(UGameplayStatics::CreateSaveGameObject(USaveSystem::StaticClass())))
	{
		// SaveGame 오브젝트에 데이터를 설정합니다.
		SaveGameInstance->SlotName = TEXT("PlayerOne2");
		SaveGameInstance->UserIndex = 0;
		SaveGameInstance->PlayerClass = PlayerClass;
		SaveGameInstance->PlayerStatus = FCharacterStatus();

		// 즉시 데이터를 저장합니다.
		if (UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("PlayerOne"), 0))
		{
			DebugLog::Print("Success Save");
			// 저장에 성공했습니다.
		}
	}
}

void UWCreateCharacter::OnClick_Btn_Back()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("SelectCharacter"));
}

