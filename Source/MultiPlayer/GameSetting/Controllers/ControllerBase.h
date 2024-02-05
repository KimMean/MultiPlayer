#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ControllerBase.generated.h"

class UInputMappingContext;

UCLASS()
class MULTIPLAYER_API AControllerBase : public APlayerController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSoftObjectPtr<UInputMappingContext> InputMapping;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int Priority = 0;

public :
	AControllerBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void JoinServer();

protected:
	virtual void OnPossess(APawn* InPawn);
	virtual void OnUnPossess();

};
