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
	/* Profile 버튼 클릭 이벤트 */
	UFUNCTION() void ProfileButtonOnClick();
	/* Inventory 버튼 클릭 이벤트 */
	UFUNCTION() void InventoryButtonOnClick();
	/* Store 버튼 클릭 이벤트 */
	UFUNCTION() void StoreButtonOnClick();
	/* Option 버튼 클릭 이벤트 */
	UFUNCTION() void OptionButtonOnClick();
	/* Join 버튼 클릭 이벤트 */
	UFUNCTION() void JoinButtonOnClick();
	/* Change 버튼 클릭 이벤트 */
	UFUNCTION() void ChangeButtonOnClick();
	/* Quit 버튼 클릭 이벤트 */
	UFUNCTION() void QuitButtonOnClick();
	/* Ready 버튼 클릭 이벤트 */
	UFUNCTION() void ReadyButtonOnClick();


private:
	/* 내 정보를 확인하기 위한 버튼입니다.*/
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Profile;

	/* 창고와 소지품을 확인하기 위한 버튼입니다.*/
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Inventory;

	/* 상점을 열기 위한 버튼입니다.*/
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Store;
	
	/* 게임의 전반적인 설정을 바꾸기 위한 버튼입니다. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Option;

	/* 다른 서버에 참가하기 위한 버튼입니다. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Join;

	/* 방장의 권한으로 맵을 변경하기 위한 버튼입니다. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Change;

	/* 게임을 종료하기 위한 버튼입니다. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Quit;

	/* 게임을 시작하기 위해 준비 상태로 전환하기 위한 버튼입니다. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Ready;
};
