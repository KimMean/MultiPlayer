
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerInventory.generated.h"

class UGridPanel;
class UInventorySlot;

#define INVENTORY_SLOT_COLUMN 12
#define INVENTORY_SLOT_ROW 7

UCLASS()
class MULTIPLAYER_API UPlayerInventory : public UUserWidget
{
	GENERATED_BODY()
	
public :
	UPlayerInventory(const FObjectInitializer& ObjectInitializer);

	virtual void NativeConstruct() override;

protected :
	UPROPERTY(meta = (BindWidget))
		TObjectPtr<UGridPanel> GridPanel;

	TArray<TObjectPtr<UInventorySlot>> InventorySlots;
};
