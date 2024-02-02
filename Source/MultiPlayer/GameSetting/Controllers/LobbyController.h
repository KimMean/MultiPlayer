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

	// ���� �����ÿ��� �ٲ��� �ʾ���.
	/* ��Ȱ�� �̵� �� ������ PC�� �� PC�� ��ü�� �� ȣ��˴ϴ�. */
	virtual void SeamlessTravelTo(class APlayerController* NewPC) override;

	/* ��Ȱ�� �̵� �� ������ PC�� �� PC�� ��ü�� �� ȣ��˴ϴ�. */
	virtual void SeamlessTravelFrom(class APlayerController* OldPC) override;

	/* �� �÷��̾� ��Ʈ�ѷ��� ��Ȱ�� �̵��� ���� ��ȯ�� �� �ش� �÷��̾ �ʱ�ȭ�Ǳ� ���� ȣ��˴ϴ�. */
	virtual void PostSeamlessTravel() override;
};
