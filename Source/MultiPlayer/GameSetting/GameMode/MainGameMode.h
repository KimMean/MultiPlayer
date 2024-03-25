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
	* EnemyType�� ���� ������ ����ġ�� ��ȯ�մϴ�.
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
	/* DataTable�� �����մϴ�. */
	TObjectPtr<UDataTable> DT_TacticsWeight;
	/* ������ ����ġ�� ������ ���ۺ��� ������ ������ �ֽ��ϴ�. */
	TMap<EEnemyType, TArray<float>> TacticalWeightsOfEnemyType;

	/* �� ���� */
	TObjectPtr<UDataTable> DT_EnemyStatus;
	TMap<FString, FCharacterStatus*> EnemyStatus;
};
