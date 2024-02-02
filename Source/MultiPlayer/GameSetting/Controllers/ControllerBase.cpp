#include "GameSetting/Controllers/ControllerBase.h"

#include "GameSetting/PlayerCameraManager/PlayerCameraManagerBase.h"

#include "Utilities/DebugLog.h"

AControllerBase::AControllerBase()
{
	bShowMouseCursor = true;
	PlayerCameraManagerClass = APlayerCameraManagerBase::StaticClass();
}

void AControllerBase::BeginPlay()
{
	DebugLog::Print((int)GetRemoteRole());
}

void AControllerBase::JoinServer()
{
}
