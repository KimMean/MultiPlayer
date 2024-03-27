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
	/* ���� �ν��Ͻ��� ���������� ���۵ǰų� PIE�� ���� ���۵� �� ȣ��˴ϴ�. */
	virtual void OnStart() override;
	virtual void Shutdown() override;


	int32 GetPlayerSlotIndex();
	void SetPlayerSlotIndex(int32 InSlotIndex);

	void CreateCharacter(TObjectPtr<APlayerBase> InPlayerCharacter);

protected :
	int32 PlayerSlotIndex;

	TObjectPtr<APlayerBase> PlayerCharacters;
};
