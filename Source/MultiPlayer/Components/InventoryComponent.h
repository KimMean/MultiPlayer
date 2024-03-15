#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

class UPlayerInventory;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYER_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UInventoryComponent();

protected:
	virtual void BeginPlay() override;


protected :
	UPROPERTY(VisibleDefaultsOnly)
		TSubclassOf<UPlayerInventory> InventoryWidgetClass;
	UPROPERTY(VisibleDefaultsOnly)
		TObjectPtr<UPlayerInventory> InventoryWidget;
		
};
