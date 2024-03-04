#include "GameSetting/GameInstance/GameInstanceBase.h"

#include "Datas/EnemyData/DataTable_TacticsWeight.h"

#include "Utilities/DebugLog.h"

UGameInstanceBase::UGameInstanceBase()
{
	ConstructorHelpers::FObjectFinder<UDataTable> TacticalWeightsData(TEXT("/Script/Engine.DataTable'/Game/Blueprints/Enemies/Datas/DT_TacticalWeights.DT_TacticalWeights'"));
	DT_TacticsWeight = TacticalWeightsData.Object;
}

void UGameInstanceBase::Init()
{
	Super::Init();

	TArray<FTacticsWeightData*> datas;
	DT_TacticsWeight->GetAllRows<FTacticsWeightData>("", datas);

	for (const FTacticsWeightData* data : datas)
	{
		TArray<float> weights({ data->AttackWeight, data->DefendWeight, data->EvadeWeight });
		TacticalWeightsOfEnemyType.Add(data->EnemyType, weights);
	}
	DebugLog::Print("GameInstanceBase Init");
}

void UGameInstanceBase::OnStart()
{
	Super::OnStart();
	DebugLog::Print("GameInstanceBase OnStart");
}

const TArray<float> UGameInstanceBase::GetTacticalWeights_Of_EnemyType(EEnemyType InEnemyType)
{
	return TacticalWeightsOfEnemyType[InEnemyType];
}
