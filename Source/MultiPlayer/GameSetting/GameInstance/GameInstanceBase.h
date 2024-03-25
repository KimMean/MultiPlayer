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

	void CreateCharacter(APlayerBase& InPlayerCharacter);

protected :
	TArray<TObjectPtr<APlayerBase>> PlayerCharacters;
};
