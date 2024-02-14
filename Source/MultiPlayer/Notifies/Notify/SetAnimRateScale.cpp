#include "Notifies/Notify/SetAnimRateScale.h"

USetAnimRateScale::USetAnimRateScale()
{

}

void USetAnimRateScale::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::Notify(MeshComp, Animation, EventReference);

	Animation->RateScale = RateScale;
}

