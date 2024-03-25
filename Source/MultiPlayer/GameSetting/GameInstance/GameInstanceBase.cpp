#include "GameSetting/GameInstance/GameInstanceBase.h"

#include "Utilities/DebugLog.h"

UGameInstanceBase::UGameInstanceBase()
{
}

void UGameInstanceBase::Init()
{
	Super::Init();
	DebugLog::Print("GameInstanceBase Init");

	// ĳ���� ���� Load
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
	// ��
	PlayerCharacters.Add(InPlayerCharacter);
}

