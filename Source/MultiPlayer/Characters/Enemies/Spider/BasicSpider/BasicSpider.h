#pragma once

#include "CoreMinimal.h"
#include "Characters/Enemies/Spider/SpiderBase.h"
#include "BasicSpider.generated.h"

/*
* 
*/

class AWeaponBase;

UCLASS()
class MULTIPLAYER_API ABasicSpider : public ASpiderBase
{
	GENERATED_BODY()

public:
	ABasicSpider();

	//~ Begin ASpiderBase Interface.
	virtual void PostInitializeComponents() override;
	//~ End ASpiderBase Interface.

protected:
	virtual void BeginPlay() override;
};
