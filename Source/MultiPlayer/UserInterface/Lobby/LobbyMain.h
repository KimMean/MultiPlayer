#pragma once

#include "CoreMinimal.h"
#include "UserInterface/UserWidgetBase.h"
#include "LobbyMain.generated.h"

class UButton;

UCLASS()
class MULTIPLAYER_API ULobbyMain : public UUserWidgetBase
{
	GENERATED_BODY()
	

protected:
	virtual void NativeConstruct() override;


public:
	UFUNCTION() void OnlineServerButtonOnClick();
	UFUNCTION() void HostServerButtonOnClick();
	UFUNCTION() void JoinServerButtonOnClick();
	UFUNCTION() void OptionButtonOnClick();
	UFUNCTION() void QuitButtonOnClick();


private:
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_OnlineServer;
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_HostServer;
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_JoinServer;
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Option;
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Quit;
};
