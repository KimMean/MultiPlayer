#include "Components/InventoryComponent.h"

#include "Characters/PlayerCharacter/PlayerBase.h"
#include "UserInterface/Player/InventorySystem/PlayerInventory.h"

UInventoryComponent::UInventoryComponent()
{

	ConstructorHelpers::FClassFinder<UPlayerInventory> ui(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/Player/Inventory/WB_Inventory.WB_Inventory_C'"));
	InventoryWidgetClass = ui.Class;
}

void UInventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	InventoryWidget = CreateWidget<UPlayerInventory>(Cast<APlayerBase>(GetOwner())->GetController<APlayerController>(), InventoryWidgetClass);
	if (InventoryWidget)
	{
		InventoryWidget->Initialize();
		InventoryWidget->AddToViewport();
	}
}


