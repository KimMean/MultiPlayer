#include "Utilities/DebugLog.h"
#include "Engine.h"

DEFINE_LOG_CATEGORY_STATIC(GameProject, Display, All)

DebugLog::DebugLog()
{
}

DebugLog::~DebugLog()
{
}

void DebugLog::Print(int32 InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, FString::FromInt(InValue));
}

void DebugLog::Print(float InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, FString::SanitizeFloat(InValue));
}

void DebugLog::Print(const FString& InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue);
}

void DebugLog::Print(const FVector& InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue.ToString());
}

void DebugLog::Print(const FRotator& InValue, int32 InKey, float Duration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, InValue.ToString());
}

void DebugLog::Print(const UObject* InObject, int32 InKey, float Duration, FColor InColor)
{
	FString str;
	if (!!InObject)
		str.Append(InObject->GetName());

	str.Append(!!InObject ? "Not Null" : "Null");
	GEngine->AddOnScreenDebugMessage(InKey, Duration, InColor, str);
}

void DebugLog::Log(int32 InValue)
{
	UE_LOG(GameProject, Display, L"%d", InValue);
}

void DebugLog::Log(float InValue)
{
	UE_LOG(GameProject, Display, L"%f", InValue);
}

void DebugLog::Log(const FString& InValue)
{
	UE_LOG(GameProject, Display, L"%s", *InValue);
}

void DebugLog::Log(const FVector& InValue)
{
	UE_LOG(GameProject, Display, L"%s", *InValue.ToString());
}

void DebugLog::Log(const FRotator& InValue)
{
	UE_LOG(GameProject, Display, L"%s", *InValue.ToString());
}

void DebugLog::Log(const UObject* InObject)
{
	FString str;
	if (!!InObject)
		str.Append(InObject->GetName());

	str.Append(!!InObject ? "Not Null" : "Null");
	UE_LOG(GameProject, Display, L"%s", *str);
}

void DebugLog::Log(const FString& InFuncName, int32 InLineNumber)
{
	FString str;
	str.Append(InFuncName);
	str.Append(", ");
	str.Append(FString::FromInt(InLineNumber));

	UE_LOG(GameProject, Display, L"%s", *str);
}

void DebugLog::DrawLine(const UWorld* InWorld, FVector const& LineStart, FVector const& LineEnd, FColor const& Color, bool bPersistentLines, float LifeTime, float Thickness)
{
	DrawDebugLine(InWorld, LineStart, LineEnd, Color, bPersistentLines, LifeTime, 0, Thickness);
}

void DebugLog::DrawCircle(const UWorld* InWorld, const FVector Center, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Tickness)
{
	DrawDebugCircle(InWorld, Center, Radius, Segments, Color, bPersistentLines, LifeTime, DepthPriority, Tickness);
}

void DebugLog::DrawCapsule(const UWorld* InWorld, FVector const& Center, float HalfHeight, float Radius, FColor const& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Tickness)
{
	DrawDebugCapsule(InWorld, Center, HalfHeight, Radius, FRotator(0.0f, 0.0f, 0.0f).Quaternion(), Color, bPersistentLines, LifeTime, DepthPriority, Tickness);
}

void DebugLog::DrawSphere(const UWorld* InWorld, FVector const& Center, float Radius, FColor const& Color, float LifeTime, int32 Segments, bool bPersistentLines, uint8 DepthPriority, float Tickness)
{
	DrawDebugSphere(InWorld, Center, Radius, Segments, Color, bPersistentLines, LifeTime, DepthPriority, Tickness);
}