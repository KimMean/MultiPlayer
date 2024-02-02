#pragma once

#include "CoreMinimal.h"
#include "GameSetting/Controllers/ControllerBase.h"
#include "LobbyController.generated.h"

UCLASS()
class MULTIPLAYER_API ALobbyController : public AControllerBase
{
	GENERATED_BODY()
	
public :
	ALobbyController();

protected :
	virtual void BeginPlay() override;

public :
	virtual void JoinServer() override;

	// 서버 참여시에는 바뀌지 않았음.
	/* 원활한 이동 및 지정된 PC가 이 PC로 교체될 때 호출됩니다. */
	virtual void SeamlessTravelTo(class APlayerController* NewPC) override;

	/* 원활한 이동 및 지정된 PC가 이 PC로 교체될 때 호출됩니다. */
	virtual void SeamlessTravelFrom(class APlayerController* OldPC) override;

	/* 이 플레이어 컨트롤러가 원활한 이동을 통해 전환된 후 해당 플레이어가 초기화되기 전에 호출됩니다. */
	virtual void PostSeamlessTravel() override;
};
