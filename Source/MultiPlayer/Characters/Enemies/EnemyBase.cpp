#include "Characters/Enemies/EnemyBase.h"

#include "GameSetting/GameInstance/GameInstanceBase.h"
#include "GameSetting/Controllers/AIControllerBase.h"
#include "Components/Enemy/EnemyAnimationComponent.h"

#include "Utilities/DebugLog.h"

AEnemyBase::AEnemyBase()
{
	SetGenericTeamId(2);

	State = CreateDefaultSubobject<UEnemyStateComponent>(TEXT("StateComponent"));
	Animation = CreateDefaultSubobject<UEnemyAnimationComponent>(TEXT("AnimationComponent"));

	AIController = AAIControllerBase::StaticClass();
	AIControllerClass = AIController;

	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	State->OnEnemyStateTypeChanged.AddDynamic(this, &AEnemyBase::OnEnemyStateChanged);

	DebugLog::Print(GetGenericTeamId());

	DebugLog::Print((Cast<UGameInstanceBase>(GetWorld()->GetGameInstance())->GetTacticalWeights_Of_EnemyType(EEnemyType::NONE))[0]);
}

UBehaviorTree* AEnemyBase::GetBehaviorTree()
{
	return BehaviorTree;
}

UEnemyStateComponent* AEnemyBase::GetEnemyStateComponent()
{
	return State;
}

UEnemyAnimationComponent* AEnemyBase::GetEnemyAnimationComponent()
{
	return Animation;
}

void AEnemyBase::OnEnemyStateChanged(EEnemyStateType InPrevType, EEnemyStateType InNewType)
{
	//
}

EEnemyType AEnemyBase::GetEnemyType()
{
	return EnemyType;
}
