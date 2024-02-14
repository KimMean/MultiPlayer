#include "Notifies/Notify/ResetEvationState.h"
#include "Characters/PlayerCharacter/PlayerBase.h"

#include "Utilities/DebugLog.h"

UResetEvationState::UResetEvationState()
{

}

void UResetEvationState::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	if (MeshComp->GetOwner() == nullptr)
	{
		DebugLog::Print(L"ResetEvationState - MeshComp == nullptr");
		return;
	}

	APlayerBase* player = Cast<APlayerBase>(MeshComp->GetOwner());
	if (player == nullptr)
	{
		DebugLog::Print(L"ResetEvationState - Player == nullptr");
		return;
	}

	DebugLog::Print(L"ResetEvation");
	player->ResetEvation();
}
