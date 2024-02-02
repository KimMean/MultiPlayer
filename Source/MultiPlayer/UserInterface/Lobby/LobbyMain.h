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
	/* Profile ��ư Ŭ�� �̺�Ʈ */
	UFUNCTION() void ProfileButtonOnClick();
	/* Inventory ��ư Ŭ�� �̺�Ʈ */
	UFUNCTION() void InventoryButtonOnClick();
	/* Store ��ư Ŭ�� �̺�Ʈ */
	UFUNCTION() void StoreButtonOnClick();
	/* Option ��ư Ŭ�� �̺�Ʈ */
	UFUNCTION() void OptionButtonOnClick();
	/* Join ��ư Ŭ�� �̺�Ʈ */
	UFUNCTION() void JoinButtonOnClick();
	/* Change ��ư Ŭ�� �̺�Ʈ */
	UFUNCTION() void ChangeButtonOnClick();
	/* Quit ��ư Ŭ�� �̺�Ʈ */
	UFUNCTION() void QuitButtonOnClick();
	/* Ready ��ư Ŭ�� �̺�Ʈ */
	UFUNCTION() void ReadyButtonOnClick();


private:
	/* �� ������ Ȯ���ϱ� ���� ��ư�Դϴ�.*/
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Profile;

	/* â��� ����ǰ�� Ȯ���ϱ� ���� ��ư�Դϴ�.*/
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Inventory;

	/* ������ ���� ���� ��ư�Դϴ�.*/
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Store;
	
	/* ������ �������� ������ �ٲٱ� ���� ��ư�Դϴ�. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Option;

	/* �ٸ� ������ �����ϱ� ���� ��ư�Դϴ�. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Join;

	/* ������ �������� ���� �����ϱ� ���� ��ư�Դϴ�. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Change;

	/* ������ �����ϱ� ���� ��ư�Դϴ�. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Quit;

	/* ������ �����ϱ� ���� �غ� ���·� ��ȯ�ϱ� ���� ��ư�Դϴ�. */
	UPROPERTY(meta = (BindWidget))
		UButton* Btn_Ready;
};
