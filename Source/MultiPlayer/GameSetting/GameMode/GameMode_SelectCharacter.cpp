#include "GameSetting/GameMode/GameMode_SelectCharacter.h"

#include "Kismet/GameplayStatics.h"

#include "Characters/PawnBase.h"

AGameMode_SelectCharacter::AGameMode_SelectCharacter()
{
	DefaultPawnClass = APawnBase::StaticClass();
}

void AGameMode_SelectCharacter::BeginPlay()
{
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	controller->SetShowMouseCursor(true);
}

void AGameMode_SelectCharacter::Travel_CreateCharacter()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("CreateCharacter"));
}
