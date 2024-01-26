#include "Characters/PlayerCharacter/Components/CameraControlComponent.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


UCameraControlComponent::UCameraControlComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 300.0f;
	SpringArm->SetRelativeLocation(FVector(0, 30, 90));
	
}


void UCameraControlComponent::BeginPlay()
{
	Super::BeginPlay();

	
}


void UCameraControlComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}

