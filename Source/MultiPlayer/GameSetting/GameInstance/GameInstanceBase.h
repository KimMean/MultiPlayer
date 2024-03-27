#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstanceBase.generated.h"

class APlayerBase;

UCLASS()
class MULTIPLAYER_API UGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()
	
public :
	UGameInstanceBase();


	virtual void Init() override;
	/* 게임 인스턴스가 정상적으로 시작되거나 PIE를 통해 시작될 때 호출됩니다. */
	virtual void OnStart() override;
	virtual void Shutdown() override;


	int32 GetPlayerSlotIndex();
	void SetPlayerSlotIndex(int32 InSlotIndex);

	void CreateCharacter(TObjectPtr<APlayerBase> InPlayerCharacter);

protected :
	int32 PlayerSlotIndex;

	TObjectPtr<APlayerBase> PlayerCharacters;
};
