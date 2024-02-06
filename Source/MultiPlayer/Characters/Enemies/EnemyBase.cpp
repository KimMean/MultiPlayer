#include "Characters/Enemies/EnemyBase.h"

#include "GameSetting/Controllers/AIControllerBase.h"
#include "Components/ShapeComponent.h"
#include "Components/BoxComponent.h"

#include "Utilities/DebugLog.h"

AEnemyBase::AEnemyBase()
{
	SetGenericTeamId(2);

	State = CreateDefaultSubobject<UEnemyStateComponent>(TEXT("StateComponent"));

	AIController = AAIControllerBase::StaticClass();
	AIControllerClass = AIController;
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	State->OnEnemyStateTypeChanged.AddDynamic(this, &AEnemyBase::OnEnemyStateChanged);

	DebugLog::Print(GetGenericTeamId());
}

void AEnemyBase::OnEnemyStateChanged(EEnemyStateType InPrevType, EEnemyStateType InNewType)
{
	//
}
