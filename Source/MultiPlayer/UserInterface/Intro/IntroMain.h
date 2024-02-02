#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IntroMain.generated.h"

class UButton;

UCLASS()
class MULTIPLAYER_API UIntroMain : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public :
	UFUNCTION() void Btn_Check_OnClicked();
		

private :
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Check;
};
