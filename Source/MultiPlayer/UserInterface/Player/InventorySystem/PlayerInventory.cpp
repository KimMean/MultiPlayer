#include "UserInterface/Player/InventorySystem/PlayerInventory.h"

#include "Components/PanelWidget.h"
#include "Components/GridPanel.h"

#include "UserInterface/Player/InventorySystem/InventorySlot.h"

#include "Utilities/DebugLog.h"

UPlayerInventory::UPlayerInventory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}

void UPlayerInventory::NativeConstruct()
{
	Super::NativeConstruct();
	
	int32 childCount = GridPanel->GetChildrenCount();
	for (int32 i = 0; i < childCount; i++)
	{
		InventorySlots.Add(Cast<UInventorySlot>(GridPanel->GetChildAt(i)));
	}

	//InventorySlots = Cast<UInventorySlot>(GridPanel->GetAllChildren())
}
