// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "Characters/Enemies/EnemyBase.h"
#include "Characters/CharacterInformation.h"
#include "MultiPlayerGameMode.generated.h"

UCLASS(minimalapi)
class AMultiPlayerGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AMultiPlayerGameMode();
	// GameMode�� InitGame() �̺�Ʈ�� �ٸ� �Լ�(PreInitializeComponents() ����)���� ���� ȣ��˴ϴ�.
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	//GameState�� ������ �� GameMode�� PreInitializeComponents() �߿� ȣ��˴ϴ�.
	virtual void InitGameState() override;

	// ������ �����Ϸ��� �÷��̾ �����ϰų� �ź��մϴ�.
	// PreLogin�� �α��� ���� ȣ��˴ϴ�.
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	// �÷��̾� ��Ʈ�ѷ��� �����Ͽ� ���ο� �÷��̾ �α����ϵ��� ȣ��˴ϴ�.
	// �÷��̾��� �⺻ �Ӽ�(�̸�, ���� ID, �鿣�� ��� ��)�� �����մϴ�.
	// �α��ο� �����ϸ� �� �÷��̾�� ������ �� PlayerController�� ��ȯ�մϴ�. 
	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	// �α��� ���� �� ȣ��˴ϴ�. PlayerController���� ������ �Լ��� ȣ���ϴ� ���� ������ ù ��° ����Դϴ�.
	virtual void PostLogin(APlayerController* NewPlayer) override;

	// �̴� �� �÷��̾ �����ϱ� �� ������ �ܰ��Դϴ�. DispatchPostLogin�� �Ϻη� ȣ���
	virtual void OnPostLogin(AController* NewPlayer) override;


	// PlayerState�� �ִ� ��Ʈ�ѷ��� ������ �����ų� ������ �� ȣ��˴ϴ�.
	virtual void Logout(AController* Exiting) override;

protected:
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



