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
	/* ���� �ν��Ͻ��� ���������� ���۵ǰų� PIE�� ���� ���۵� �� ȣ��˴ϴ�. */
	virtual void OnStart() override;

public :
	/* 
	* EnemyType�� ���� ������ ����ġ�� ��ȯ�մϴ�. 
	* @ EEnemyType InEnemyType = Enemy->GetEnemyType
	* return TArray<float> Attack Tactical Weights 
	*/
	const TArray<float> GetTacticalWeights_Of_EnemyType(EEnemyType InEnemyType);

private :
	/* DataTable�� �����մϴ�. */
	TObjectPtr<UDataTable> DT_TacticsWeight;
	/* ������ ����ġ�� ������ ���ۺ��� ������ ������ �ֽ��ϴ�. */
	TMap<EEnemyType, TArray<float>> TacticalWeightsOfEnemyType;
};
