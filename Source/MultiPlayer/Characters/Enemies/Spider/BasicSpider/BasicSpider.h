#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemies/Spider/SpiderBase.h"
#include "BasicSpider.generated.h"

UCLASS()
class MULTIPLAYER_API ABasicSpider : public ASpiderBase
{
	GENERATED_BODY()

public:
	ABasicSpider();

protected:
	virtual void BeginPlay() override;
};
