#include "GameSetting/Controllers/AIControllerBase.h"


#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

#include "Characters/Enemies/EnemyBase.h"
#include "Utilities/DebugLog.h"

AAIControllerBase::AAIControllerBase()
{
	Blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));

	Sight->SightRadius = 600;	// 감지 범위
	Sight->LoseSightRadius = 800;	// 벗어난 범위
	Sight->PeripheralVisionAngleDegrees = 90;	//시야각

	PerceptionComponent->ConfigureSense(*Sight);	// 감지
	PerceptionComponent->SetDominantSense(*Sight->GetSenseImplementation());	// 감지 우선순위?
}

void AAIControllerBase::BeginPlay()
{
	Super::BeginPlay();
}

void AAIControllerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bDrawDebug) return;

	FVector center = OwnerEnemy->GetActorLocation();
	center.Z -= AdjustCircleHeight;
	// 원을 그릴 방향까지 지정 앞에서 오른쪽으로 시계방향
	DrawDebugCircle(GetWorld(), center, Sight->SightRadius, 300, FColor::Green, false, -1, 0, 0, FVector::RightVector, FVector::ForwardVector);
	DrawDebugCircle(GetWorld(), center, ActionRange, 300, FColor::Green, false, -1, 0, 0, FVector::RightVector, FVector::ForwardVector);
}


void AAIControllerBase::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	OwnerEnemy = Cast<AEnemyBase>(InPawn);

	PerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &AAIControllerBase::OnPerceptionUpdated);

	RunBehaviorTree(OwnerEnemy->GetBehaviorTree());
}

void AAIControllerBase::OnUnPossess()
{
	Super::OnUnPossess();

	PerceptionComponent->OnPerceptionUpdated.Clear();
}

void AAIControllerBase::OnPerceptionUpdated(const TArray<AActor*>& UpdateActors)
{
	DebugLog::Print("OnPerceptionUpdated");
}

void AAIControllerBase::SetSenseConfigSight_SightRadius(float InRadius)
{
	Sight->SightRadius = InRadius;
}

void AAIControllerBase::SetSenseConfigSight_LoseSightRadius(float InRadius)
{
	Sight->LoseSightRadius = InRadius;
}

void AAIControllerBase::SetActionRange(float InActionRange)
{
	ActionRange = InActionRange;
}
