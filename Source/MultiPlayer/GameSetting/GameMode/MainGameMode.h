#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Characters/Enemies/EnemyBase.h"
#include "Characters/CharacterInformation.h"
#include "MainGameMode.generated.h"

UCLASS()
class MULTIPLAYER_API AMainGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public :
	AMainGameMode();

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	
	virtual void InitGameState() override;

	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void OnPostLogin(AController* NewPlayer) override;


	virtual void Logout(AController* Exiting) override;

protected :
	virtual void BeginPlay() override;


public:
	/*
	* EnemyType에 따른 전술적 가중치를 반환합니다.
	* @ EEnemyType InEnemyType = Enemy->GetEnemyType
	* return TArray<float> Attack Tactical Weights
	*/
	const TArray<float> GetTacticalWeights_Of_EnemyType(EEnemyType InEnemyType);

	bool ContainsEnemyStatus(FString InEnemyName);
	const FCharacterStatus* GetEnemyStatus(FString InEnemyName);

private:
	void LoadTacticsWeightData();
	void LoadEnemyStatusData();


private:
	/* DataTable을 참조합니다. */
	TObjectPtr<UDataTable> DT_TacticsWeight;
	/* 전술적 가중치를 게임의 시작부터 끝까지 가지고 있습니다. */
	TMap<EEnemyType, TArray<float>> TacticalWeightsOfEnemyType;

	/* 적 정보 */
	TObjectPtr<UDataTable> DT_EnemyStatus;
	TMap<FString, FCharacterStatus*> EnemyStatus;
};
