#include "Characters/Enemies/EnemyBase.h"

#include "GameSetting/Controllers/AIControllerBase.h"

#include "Utilities/DebugLog.h"

AEnemyBase::AEnemyBase()
{
	AIController = AAIControllerBase::StaticClass();
	AIControllerClass = AIController;
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();
}
