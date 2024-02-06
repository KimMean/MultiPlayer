#include "GameSetting/Controllers/AIControllerBase.h"


#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"

#include "Characters/Enemies/EnemyBase.h"
#include "Utilities/DebugLog.h"

AAIControllerBase::AAIControllerBase()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));

	Sight->SightRadius = 600;	// ���� ����
	Sight->LoseSightRadius = 800;	// ��� ����
	Sight->PeripheralVisionAngleDegrees = 90;	//�þ߰�

	// TeamID�� ���� ����
	Sight->DetectionByAffiliation.bDetectEnemies = true;	// ��
	Sight->DetectionByAffiliation.bDetectNeutrals = false;	// �߸�
	Sight->DetectionByAffiliation.bDetectFriendlies = true;	// �Ʊ�

	PerceptionComponent->ConfigureSense(*Sight);	// ����
	// AI ���� ������Ʈ�� �ð� ������ �ֿ� �������� ���� 
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
	// ���� �׸� ������� ���� �տ��� ���������� �ð����
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
	// ������ Player�� �� Target Player�� �����ؾ���
	// 4���� �����Ǿ��� �� ���� �켱������ ��� �ؾ����� ���ϴ� ���� �ʿ�
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
