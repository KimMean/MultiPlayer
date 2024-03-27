#include "GameSetting/GameMode/GameMode_SelectCharacter.h"

#include "Kismet/GameplayStatics.h"

#include "System/DataSystem/SaveSystem.h"
#include "Characters/PawnBase.h"
#include "Characters/PlayerCharacter/Warrior.h"

#include "Utilities/DebugLog.h"

AGameMode_SelectCharacter::AGameMode_SelectCharacter()
{
	DefaultPawnClass = APawnBase::StaticClass();
}

void AGameMode_SelectCharacter::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
}

void AGameMode_SelectCharacter::BeginPlay()
{
	LoadCharacterData();
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	controller->SetShowMouseCursor(true);
}

void AGameMode_SelectCharacter::Travel_CreateCharacter()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("CreateCharacter"));
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

			//FPlayerData data;
			//data.Class = saveData->PlayerClass;
			//data.Status = saveData->PlayerStatus;
			//PlayerDatas[i] = data;

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
	DebugLog::Print(Player->GetCharacterStatusComponent()->GetCharacterStatus().CharacterName);
	Player->FinishSpawning(transform);
	

	return Player;
}
