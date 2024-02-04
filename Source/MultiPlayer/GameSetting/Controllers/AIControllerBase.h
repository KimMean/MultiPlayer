#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerBase.generated.h"

class UBehaviorTreeComponent;

UCLASS()
class MULTIPLAYER_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()
	
public :
	AAIControllerBase();

protected :
	virtual void BeginPlay() override;


};
