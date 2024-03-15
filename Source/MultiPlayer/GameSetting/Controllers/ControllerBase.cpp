#include "GameSetting/Controllers/ControllerBase.h"

#include "GameSetting/PlayerCameraManager/PlayerCameraManagerBase.h"
#include "InputMappingContext.h"
#include "EnhancedInputSubsystems.h"

#include "Utilities/DebugLog.h"

AControllerBase::AControllerBase()
{
	PlayerCameraManagerClass = APlayerCameraManagerBase::StaticClass();
}

void AControllerBase::BeginPlay()
{
	//DebugLog::Print((int)GetRemoteRole());

	bShowMouseCursor = false; 

	if (ULocalPlayer* localPlayer = Cast<ULocalPlayer>(Player))
	{
		if (UEnhancedInputLocalPlayerSubsystem* inputSystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
		{
			if (InputMapping.IsNull() == false)
			{
				inputSystem->AddMappingContext(InputMapping.LoadSynchronous(), Priority);
			}
		}
	}
	SetShowMouseCursor(true);
}

void AControllerBase::JoinServer()
{
}

void AControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

}

void AControllerBase::OnUnPossess()
{
	Super::OnUnPossess();

}
