#include "MultiPlayerGameMode.h"

#include "GameSetting/Controllers/ControllerBase.h"
#include "GameSetting/PlayerState/PlayerStateBase.h"
#include "GameSetting/GameState/StateBase.h"
#include "GameSetting/HUD/HUDBase.h"
#include "GameSetting/GameSession/GameSessionBase.h"
#include "GameSetting/Spectator/SpectatorBase.h"

#include "Datas/EnemyData/DataTable_TacticsWeight.h"

#include "Utilities/DebugLog.h"

AMultiPlayerGameMode::AMultiPlayerGameMode()
{
	DefaultPawnClass = ADefaultPawn::StaticClass();
	PlayerControllerClass = AControllerBase::StaticClass();
	PlayerStateClass = APlayerStateBase::StaticClass();
	GameStateClass = AStateBase::StaticClass();
	HUDClass = AHUDBase::StaticClass();
	GameSessionClass = AGameSessionBase::StaticClass();
	SpectatorClass = ASpectatorBase::StaticClass();
	ReplaySpectatorPlayerControllerClass = AControllerBase::StaticClass();
	ServerStatReplicatorClass = AServerStatReplicator::StaticClass();


	ConstructorHelpers::FObjectFinder<UDataTable> TacticalWeightsData(TEXT("/Script/Engine.DataTable'/Game/Blueprints/Enemies/Datas/DT_TacticalWeights.DT_TacticalWeights'"));
	DT_TacticsWeight = TacticalWeightsData.Object;

	ConstructorHelpers::FObjectFinder<UDataTable> enemyData(TEXT("/Script/Engine.DataTable'/Game/Blueprints/Enemies/Datas/DT_EnemyData.DT_EnemyData'"));
	DT_EnemyStatus = enemyData.Object;
}

void AMultiPlayerGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	DebugLog::Print("InitGame");
	Super::InitGame(MapName, Options, ErrorMessage);

	LoadTacticsWeightData();
	LoadEnemyStatusData();
}

void AMultiPlayerGameMode::InitGameState()
{
	DebugLog::Print("InitGameState");
	Super::InitGameState();
}

void AMultiPlayerGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	DebugLog::Print("PreLogin");
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
}

APlayerController* AMultiPlayerGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	DebugLog::Print("Login");
	return Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
}

void AMultiPlayerGameMode::PostLogin(APlayerController* NewPlayer)
{
	DebugLog::Print("PostLogin");
	Super::PostLogin(NewPlayer);
}

void AMultiPlayerGameMode::OnPostLogin(AController* NewPlayer)
{
	DebugLog::Print("OnPostLogin");
	Super::OnPostLogin(NewPlayer);
}


void AMultiPlayerGameMode::Logout(AController* Exiting)
{
	DebugLog::Print("Logout");
	Super::Logout(Exiting);
}

void AMultiPlayerGameMode::BeginPlay()
{
	Super::BeginPlay();
}


const TArray<float> AMultiPlayerGameMode::GetTacticalWeights_Of_EnemyType(EEnemyType InEnemyType)
{
	return TacticalWeightsOfEnemyType[InEnemyType];
}

bool AMultiPlayerGameMode::ContainsEnemyStatus(FString InEnemyName)
{
	return EnemyStatus.Contains(InEnemyName);
}

const FCharacterStatus* AMultiPlayerGameMode::GetEnemyStatus(FString InEnemyName)
{
	return EnemyStatus[InEnemyName];
}

void AMultiPlayerGameMode::LoadTacticsWeightData()
{
	TArray<FTacticsWeightData*> datas;
	DT_TacticsWeight->GetAllRows<FTacticsWeightData>("", datas);

	for (const FTacticsWeightData* data : datas)
	{
		TArray<float> weights({ data->AttackWeight, data->DefendWeight, data->EvadeWeight });
		TacticalWeightsOfEnemyType.Add(data->EnemyType, weights);
	}
}

void AMultiPlayerGameMode::LoadEnemyStatusData()
{
	TArray<FCharacterStatus*> datas;
	DT_EnemyStatus->GetAllRows<FCharacterStatus>("", datas);

	for (FCharacterStatus* data : datas)
	{
		//FCharacterStatus status(*data);
		EnemyStatus.Add(data->CharacterName, data);
	}
}