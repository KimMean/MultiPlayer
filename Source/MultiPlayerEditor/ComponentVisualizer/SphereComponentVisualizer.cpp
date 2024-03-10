#include "ShapeComponentVisualizer.h"

#include "SceneManagement.h"	// FPrimitiveDrawInterface

#include "MultiPlayer/System/Visualizers/ShapeComponentVisualizer.h"

void FShapeComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	const UShapeComponentVisualizer* shapeComp = Cast<const UShapeComponentVisualizer>(Component);
	if (shapeComp != nullptr)
	{
		FTransform shapeTM = shapeComp->GetComponentTransform();
		shapeTM.RemoveScaling();
		FColor color(200, 255, 255);

		switch (shapeComp->ShapeType)
		{
		case EShapeType::Box :
			{
				FVector MinPoint = shapeTM.GetTranslation() - 0.5f * shapeComp->Size; // 최소 지점 계산
				FVector MaxPoint = shapeTM.GetTranslation() + 0.5f * shapeComp->Size; // 최대 지점 계산
				FBox box(MinPoint, MaxPoint);
				DrawWireBox(PDI, box, color, SDPG_World, 1.0f);
			}
			break;
		case EShapeType::Sphere:
			DrawWireSphereAutoSides(PDI, shapeTM, color, shapeComp->Radius, SDPG_World);
			break;
		case EShapeType::Capsule:
			DrawWireCapsule(PDI, shapeTM.GetTranslation(), shapeTM.GetUnitAxis(EAxis::X), shapeTM.GetUnitAxis(EAxis::Y), shapeTM.GetUnitAxis(EAxis::Z), color, shapeComp->Radius, shapeComp->HalfHeight, 16, SDPG_World);
			break;
		}

	}
}
