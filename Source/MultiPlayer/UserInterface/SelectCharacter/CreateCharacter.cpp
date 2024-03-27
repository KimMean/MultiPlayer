#include "UserInterface/SelectCharacter/CreateCharacter.h"

#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

#include "GameSetting/GameInstance/GameInstanceBase.h"
#include "GameSetting/GameMode/GameMode_SelectCharacter.h"

void UCreateCharacter::NativeConstruct()
{
	Super::NativeConstruct();
	Btn_Create->OnClicked.AddDynamic(this, &UCreateCharacter::Btn_Create_OnClick);
}

void UCreateCharacter::Btn_Create_OnClick()
{
	// CreateWidget¿∏∑Œ ~
	Cast<UGameInstanceBase>(UGameplayStatics::GetGameInstance(GetWorld()))->SetPlayerSlotIndex(PlayerSlotIndex);
	Cast<AGameMode_SelectCharacter>(UGameplayStatics::GetGameMode(GetWorld()))->Travel_CreateCharacter();
}
