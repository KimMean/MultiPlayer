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

	Sight->SightRadius = 600;	// ���� ����
	Sight->LoseSightRadius = 800;	// ��� ����
	Sight->PeripheralVisionAngleDegrees = 90;	//�þ߰�

	// TeamID�� ���� ����
	Sight->DetectionByAffiliation.bDetectEnemies = true;	// ��
	Sight->DetectionByAffiliation.bDetectNeutrals = false;	// �߸�
	Sight->DetectionByAffiliation.bDetectFriendlies = false;	// �Ʊ�

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
	// ������ Player�� �� Target Player�� �����ؾ���
	// 4���� �����Ǿ��� �� ���� �켱������ ��� �ؾ����� ���ϴ� ���� �ʿ�
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
