#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CreateCharacter.generated.h"

class UButton;

UCLASS()
class MULTIPLAYER_API UCreateCharacter : public UUserWidget
{
	GENERATED_BODY()

protected :
	virtual void NativeConstruct() override;

public :
	UFUNCTION()
		void Btn_Create_OnClick();

public :
	/* Set in the Widget Blueprint */
	UPROPERTY(EditAnywhere)
		int32 PlayerSlotIndex;

private :
	UPROPERTY(meta = (BindWidget)) 
		UButton* Btn_Create;
};
