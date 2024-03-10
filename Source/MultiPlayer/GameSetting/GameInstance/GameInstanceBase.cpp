#include "GameSetting/GameInstance/GameInstanceBase.h"

#include "Utilities/DebugLog.h"

UGameInstanceBase::UGameInstanceBase()
{
}

void UGameInstanceBase::Init()
{
	Super::Init();
	DebugLog::Print("GameInstanceBase Init");
}

void UGameInstanceBase::OnStart()
{
	Super::OnStart();
	DebugLog::Print("GameInstanceBase OnStart");
}

