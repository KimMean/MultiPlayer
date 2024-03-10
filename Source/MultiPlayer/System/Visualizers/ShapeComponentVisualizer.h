#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ShapeComponentVisualizer.generated.h"

UENUM()
enum class EShapeType : uint8
{
	Sphere,
	Box,
	Capsule
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYER_API UShapeComponentVisualizer : public USceneComponent
{
	GENERATED_BODY()

public:	
	UShapeComponentVisualizer();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public :
	UPROPERTY(EditAnywhere, Category = "ShapeProperty")
		EShapeType ShapeType;

	UPROPERTY(EditAnywhere, Category = "ShapeProperty", meta = (EditCondition = "ShapeType == EShapeType::Sphere || ShapeType == EShapeType::Capsule", EditConditionHides))
		float Radius = 100.0f;

	UPROPERTY(EditAnywhere, Category = "ShapeProperty", meta = (EditCondition = "ShapeType == EShapeType::Box", EditConditionHides))
		FVector Size = { 100.0f, 100.0f, 100.0f };

	UPROPERTY(EditAnywhere, Category = "ShapeProperty", meta = (EditCondition = "ShapeType == EShapeType::Capsule", EditConditionHides))
		float HalfHeight = 100.0f;


};
