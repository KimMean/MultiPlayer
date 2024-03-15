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
	// GameMode의 InitGame() 이벤트는 다른 함수(PreInitializeComponents() 포함)보다 먼저 호출됩니다.
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;

	//GameState가 생성된 후 GameMode의 PreInitializeComponents() 중에 호출됩니다.
	virtual void InitGameState() override;

	// 서버에 참여하려는 플레이어를 수락하거나 거부합니다.
	// PreLogin은 로그인 전에 호출됩니다.
	virtual void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	// 플레이어 컨트롤러를 생성하여 새로운 플레이어를 로그인하도록 호출됩니다.
	// 플레이어의 기본 속성(이름, 고유 ID, 백엔드 등록 등)을 설정합니다.
	// 로그인에 성공하면 이 플레이어와 연결할 새 PlayerController를 반환합니다. 
	virtual APlayerController* Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	// 로그인 성공 후 호출됩니다. PlayerController에서 복제된 함수를 호출하는 것이 안전한 첫 번째 장소입니다.
	virtual void PostLogin(APlayerController* NewPlayer) override;

	// 이는 새 플레이어를 생성하기 전 마지막 단계입니다. DispatchPostLogin의 일부로 호출됨
	virtual void OnPostLogin(AController* NewPlayer) override;


	// PlayerState가 있는 컨트롤러가 게임을 떠나거나 삭제될 때 호출됩니다.
	virtual void Logout(AController* Exiting) override;

protected:
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



