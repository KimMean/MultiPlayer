#include "GameSetting/GameMode/GameMode_SelectCharacter.h"

#include "Kismet/GameplayStatics.h"

#include "System/DataSystem/SaveSystem.h"
#include "Characters/PawnBase.h"
#include "Characters/PlayerCharacter/Warrior.h"
#include "UserInterface//SelectCharacter/SelectCharacter.h"

#include "Utilities/DebugLog.h"

AGameMode_SelectCharacter::AGameMode_SelectCharacter()
{
	DefaultPawnClass = APawnBase::StaticClass();

	ConstructorHelpers::FClassFinder<USelectCharacter> widget(TEXT("WidgetBlueprint'/Game/UI/SelectCharacter/WB_SelectCharacter.WB_SelectCharacter_C'"));
	MainWidgetClass = widget.Class;
}

void AGameMode_SelectCharacter::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	LoadCharacterData();
}

void AGameMode_SelectCharacter::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	controller->SetShowMouseCursor(true);

	Widget = CreateWidget<USelectCharacter>(GetWorld(), MainWidgetClass);

	if (Widget)
		Widget->AddToViewport();

}

void AGameMode_SelectCharacter::Travel_CreateCharacter()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("CreateCharacter"));
}

bool AGameMode_SelectCharacter::ContainsPlayerData(int32 InIndex)
{
	return Characters.Contains(InIndex);
}

FCharacterStatus AGameMode_SelectCharacter::GetPlayerStatus(int32 InIndex)
{
	return Characters[InIndex]->GetCharacterStatusComponent()->GetCharacterStatus();
}

void AGameMode_SelectCharacter::SelectCharacter(int32 InIndex)
{
	Characters[CurrentSlotIndex]->SetVisibility(false);
	Characters[InIndex]->SetVisibility(true);
	CurrentSlotIndex = InIndex;

	Widget->ShowCharacterInformation(Characters[InIndex]->GetPlayerClass(), Characters[InIndex]->GetCharacterStatusComponent()->GetCharacterStatus());
}

void AGameMode_SelectCharacter::LoadCharacterData()
{
	for (int32 i = 0; i < MaxSlotCount; i++)
	{
		if (USaveSystem* saveData = Cast<USaveSystem>(UGameplayStatics::LoadGameFromSlot(SlotName + FString::FromInt(i), 0)))
		{
			//Characters.Add(i, )
			TObjectPtr<APlayerBase> player = CreateCharacterForm(saveData->PlayerClass, saveData->PlayerStatus);
			Characters.Add(i, player);

			DebugLog::Print("Load Success");
		}
	}
}

TObjectPtr<APlayerBase> AGameMode_SelectCharacter::CreateCharacterForm(EPlayerClass InClass, FCharacterStatus InStatus)
{

	TObjectPtr<APlayerBase> Player;
	
	FTransform transform;
	Player = GetWorld()->SpawnActorDeferred<APlayerBase>(AWarrior::StaticClass(), transform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	Cast<AWarrior>(Player)->GetCharacterStatusComponent()->SetCharacterStatus(InStatus);
	Player->SetActorRotation(FRotator(0, 180, 0));
	Player->SetActorLocation(FVector(0, 0, Player->GetDefaultHalfHeight()));
	Player->SetVisibility(false);
	Player->SetCapsuleComponentCollisionEnabled(ECollisionEnabled::NoCollision);
	DebugLog::Print(Player->GetCharacterStatusComponent()->GetCharacterStatus().CharacterName);
	Player->FinishSpawning(transform);
	

	return Player;
}
