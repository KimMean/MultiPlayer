#include "Characters/PawnBase.h"

#include "Camera/CameraComponent.h"

APawnBase::APawnBase()
{
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"));

	SetRootComponent(SceneComponent);
	CameraComponent->SetupAttachment(RootComponent);
}

void APawnBase::BeginPlay()
{
	Super::BeginPlay();
	
}

