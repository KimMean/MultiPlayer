#include "GameSetting/GameInstance/GameInstanceBase.h"

#include "Utilities/DebugLog.h"

UGameInstanceBase::UGameInstanceBase()
{
}

void UGameInstanceBase::Init()
{
	Super::Init();
	DebugLog::Print("GameInstanceBase Init");

	// 캐릭터 정보 Load
}

void UGameInstanceBase::OnStart()
{
	Super::OnStart();
	DebugLog::Print("GameInstanceBase OnStart");
}

void UGameInstanceBase::Shutdown()
{
	Super::Shutdown();
	DebugLog::Print("GameInstanceBase Shutdown");
}

void UGameInstanceBase::CreateCharacter(APlayerBase& InPlayerCharacter)
{
	// 흠
	PlayerCharacters.Add(InPlayerCharacter);
}

