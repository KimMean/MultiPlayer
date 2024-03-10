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
	/* ���� �ν��Ͻ��� ���������� ���۵ǰų� PIE�� ���� ���۵� �� ȣ��˴ϴ�. */
	virtual void OnStart() override;

};
