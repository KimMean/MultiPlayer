#include "GameSetting/Controllers/AIControllerBase.h"


#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

#include "Characters/Enemies/EnemyBase.h"
#include "Components/StateComponent.h"
#include "Utilities/DebugLog.h"

AAIControllerBase::AAIControllerBase()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));

	Sight->SightRadius = 600;	// 감지 범위
	Sight->LoseSightRadius = 800;	// 벗어난 범위
	Sight->PeripheralVisionAngleDegrees = 90;	//시야각

	// TeamID에 의해 결정
	Sight->DetectionByAffiliation.bDetectEnemies = true;	// 적
	Sight->DetectionByAffiliation.bDetectNeutrals = false;	// 중립
	Sight->DetectionByAffiliation.bDetectFriendlies = false;	// 아군

	PerceptionComponent->ConfigureSense(*Sight);	// 감지
	// AI 지각 컴포넌트에 시각 감각을 주요 감각으로 설정 
	PerceptionComponent->SetDominantSense(*Sight->GetSenseImplementation());
}

void AAIControllerBase::BeginPlay()
{
	Super::BeginPlay();
	DebugLog::Print("BeginPlay");
	DebugLog::Print(Blackboard);
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

	// StateType Change Delegate
	OwnerEnemy->GetCharacterStateComponent()->CharacterStateChangedDelegate.AddDynamic(this, &AAIControllerBase::OnCharacterStateChanged);

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

	//TArray<AActor*> actors;
	//PerceptionComponent->GetCurrentlyPerceivedActors(nullptr, actors);
	ACharacter* player = nullptr;
	for (AActor* actor : UpdateActors)
	{
		if (actor->ActorHasTag("Enemy")) continue;
		player = Cast<ACharacter>(actor);

		if (!!player)
			break;
	}
	Blackboard->SetValueAsObject(TEXT("Target"), player);
	// 감지된 Player들 중 Target Player를 선정해야함
	// 4명이 감지되었을 때 공격 우선순위를 어떻게 해야할지 정하는 것이 필요
}

const TObjectPtr<AActor> AAIControllerBase::GetTargetActor()
{
	TObjectPtr<AActor> actor = Cast<AActor>(Blackboard->GetValueAsObject(TEXT("Target")));

	if (actor != nullptr)
		return actor;

	return nullptr;
}

float AAIControllerBase::GetSenseConfigSight_SightRadius()
{
	return Sight->SightRadius;
}

void AAIControllerBase::SetSenseConfigSight_SightRadius(float InRadius)
{
	Sight->SightRadius = InRadius;
}

void AAIControllerBase::SetSenseConfigSight_LoseSightRadius(float InRadius)
{
	Sight->LoseSightRadius = InRadius;
}

float AAIControllerBase::GetActionRange()
{
	return ActionRange;
}

void AAIControllerBase::SetActionRange(float InActionRange)
{
	ActionRange = InActionRange;
}

void AAIControllerBase::OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState)
{
	Blackboard->SetValueAsEnum(TEXT("State"), (uint8)InNewState);
}
