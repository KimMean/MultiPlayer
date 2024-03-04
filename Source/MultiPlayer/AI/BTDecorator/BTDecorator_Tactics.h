#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "Enums/CharacterState.h"
#include "BTDecorator_Tactics.generated.h"

USTRUCT()
struct FTacticalData
{
	GENERATED_BODY()

public :
	UPROPERTY(EditAnywhere)
		ECharacterState State;
	UPROPERTY(EditAnywhere)
		float Value;
};

UCLASS()
class MULTIPLAYER_API UBTDecorator_Tactics : public UBTDecorator
{
	GENERATED_BODY()

public:
	UBTDecorator_Tactics();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	UPROPERTY(EditAnywhere)
		TArray<FTacticalData> TacticalDatas;
};
