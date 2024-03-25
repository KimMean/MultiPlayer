#include "GameSetting/GameMode/MainGameMode.h"

#include "GameSetting/Controllers/ControllerBase.h"
#include "GameSetting/PlayerState/PlayerStateBase.h"
#include "GameSetting/GameState/StateBase.h"
#include "GameSetting/HUD/HUDBase.h"
#include "GameSetting/GameSession/GameSessionBase.h"
#include "GameSetting/Spectator/SpectatorBase.h"

#include "Datas/EnemyData/DataTable_TacticsWeight.h"

#include "Utilities/DebugLog.h"

AMainGameMode::AMainGameMode()
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

void AMainGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	DebugLog::Print("AMainGameMode : InitGame");
	Super::InitGame(MapName, Options, ErrorMessage);

	LoadTacticsWeightData();
	LoadEnemyStatusData();
}

void AMainGameMode::InitGameState()
{
	DebugLog::Print("AMainGameMode : InitGameState");
	Super::InitGameState();
}

void AMainGameMode::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	DebugLog::Print("AMainGameMode : PreLogin");
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
}

APlayerController* AMainGameMode::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	DebugLog::Print("AMainGameMode : Login");
	return Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
}

void AMainGameMode::PostLogin(APlayerController* NewPlayer)
{
	DebugLog::Print("AMainGameMode : PostLogin");
	Super::PostLogin(NewPlayer);
}

void AMainGameMode::OnPostLogin(AController* NewPlayer)
{
	DebugLog::Print("AMainGameMode : OnPostLogin");
	Super::OnPostLogin(NewPlayer);
}


void AMainGameMode::Logout(AController* Exiting)
{
	DebugLog::Print("AMainGameMode : Logout");
	Super::Logout(Exiting);
}

void AMainGameMode::BeginPlay()
{
	Super::BeginPlay();
}

const TArray<float> AMainGameMode::GetTacticalWeights_Of_EnemyType(EEnemyType InEnemyType)
{
	return TacticalWeightsOfEnemyType[InEnemyType];
}

bool AMainGameMode::ContainsEnemyStatus(FString InEnemyName)
{
	return EnemyStatus.Contains(InEnemyName);
}

const FCharacterStatus* AMainGameMode::GetEnemyStatus(FString InEnemyName)
{
	return EnemyStatus[InEnemyName];
}

void AMainGameMode::LoadTacticsWeightData()
{
	TArray<FTacticsWeightData*> datas;
	DT_TacticsWeight->GetAllRows<FTacticsWeightData>("", datas);

	for (const FTacticsWeightData* data : datas)
	{
		TArray<float> weights({ data->AttackWeight, data->DefendWeight, data->EvadeWeight });
		TacticalWeightsOfEnemyType.Add(data->EnemyType, weights);
	}
}

void AMainGameMode::LoadEnemyStatusData()
{
	TArray<FCharacterStatus*> datas;
	DT_EnemyStatus->GetAllRows<FCharacterStatus>("", datas);

	for (FCharacterStatus* data : datas)
	{
		//FCharacterStatus status(*data);
		EnemyStatus.Add(data->CharacterName, data);
	}
}