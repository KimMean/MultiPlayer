#include "Notifies/NotifyState/ControlAnimRateScale.h"

#include "Curves/CurveFloat.h"
#include "Utilities/DebugLog.h"

UControlAnimRateScale::UControlAnimRateScale()
{

}

void UControlAnimRateScale::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration, EventReference);

	if (Curve == nullptr) return;
	if (bTakeOverRateScale == true)
		StartRateScale = Animation->RateScale;

	Duration = EventReference.GetNotify()->GetDuration();
	CurTime = EventReference.GetCurrentAnimationTime();

	CurveDuration = Curve->FloatCurve.GetLastKey().Time;
	DebugLog::Print("NotifyState - " + FString::SanitizeFloat(CurveDuration));
}

void UControlAnimRateScale::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime, EventReference);

	if (Curve == nullptr) return;

	Duration = EventReference.GetNotify()->GetDuration();
	CurTime = EventReference.GetCurrentAnimationTime();
	float specifiedTime = CurTime / Duration * CurveDuration;
	
	float rateScale = FMath::Lerp(StartRateScale, EndRateScale, Curve->GetFloatValue(specifiedTime));
	Animation->RateScale = rateScale;
}

void UControlAnimRateScale::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
	Super::NotifyEnd(MeshComp, Animation, EventReference);

	if (Curve == nullptr) return;
}
