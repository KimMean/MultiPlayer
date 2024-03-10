#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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

};
