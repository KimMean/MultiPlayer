#include "System/Visualizers/ShapeComponentVisualizer.h"

UShapeComponentVisualizer::UShapeComponentVisualizer()
{
	PrimaryComponentTick.bCanEverTick = true;

}

void UShapeComponentVisualizer::BeginPlay()
{
	Super::BeginPlay();
	
}


void UShapeComponentVisualizer::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
