#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Characters/CharacterInformation.h"
#include "Definitions/PlayerDefinition.h"
#include "GameMode_SelectCharacter.generated.h"

class APlayerBase;
class USelectCharacter;

USTRUCT()
struct FPlayerData
{
	GENERATED_BODY()

public :
	UPROPERTY(EditDefaultsOnly)
		EPlayerClass Class;

	UPROPERTY(EditDefaultsOnly)
		FCharacterStatus Status;
};

UCLASS()
class MULTIPLAYER_API AGameMode_SelectCharacter : public AGameModeBase
{
	GENERATED_BODY()
	
public :
	AGameMode_SelectCharacter();

	// ~ Begin AGameModeBase Interface
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	// ~ End AGameModeBase Interface

protected :
	virtual void BeginPlay() override;

public :
	void Travel_CreateCharacter();
	bool ContainsPlayerData(int32 InIndex);
	FCharacterStatus GetPlayerStatus(int32 InIndex);
	void SelectCharacter(int32 InIndex);

protected :
	void LoadCharacterData();
	TObjectPtr<APlayerBase> CreateCharacterForm(EPlayerClass InClass, FCharacterStatus InStatus);


protected :
	TMap<int32, TObjectPtr<APlayerBase>> Characters;

private:
	TSubclassOf<USelectCharacter> MainWidgetClass;
	TObjectPtr<USelectCharacter> Widget;

private :
	int32 CurrentSlotIndex;

	const int32 MaxSlotCount = 5;
	const FString SlotName = "CharacterSlot";
};
