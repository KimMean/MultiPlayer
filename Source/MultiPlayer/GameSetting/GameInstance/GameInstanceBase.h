#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Characters/Enemies/EnemyBase.h"
#include "GameInstanceBase.generated.h"

class UDataTable_TacticsWeight;

UCLASS()
class MULTIPLAYER_API UGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()
	
public :
	UGameInstanceBase();


	virtual void Init() override;
	/* 게임 인스턴스가 정상적으로 시작되거나 PIE를 통해 시작될 때 호출됩니다. */
	virtual void OnStart() override;

public :
	/* 
	* EnemyType에 따른 전술적 가중치를 반환합니다. 
	* @ EEnemyType InEnemyType = Enemy->GetEnemyType
	* return TArray<float> Attack Tactical Weights 
	*/
	const TArray<float> GetTacticalWeights_Of_EnemyType(EEnemyType InEnemyType);

private :
	/* DataTable을 참조합니다. */
	TObjectPtr<UDataTable> DT_TacticsWeight;
	/* 전술적 가중치를 게임의 시작부터 끝까지 가지고 있습니다. */
	TMap<EEnemyType, TArray<float>> TacticalWeightsOfEnemyType;
};
