#include "Characters/Enemies/EnemyBase.h"

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

#include "GameSetting/GameInstance/GameInstanceBase.h"
#include "GameSetting/Controllers/AIControllerBase.h"
#include "Components/Enemy/EnemyAnimationComponent.h"
#include "Components/WidgetComponent.h"

#include "UserInterface/Enemies/EnemyInfoWidget.h"


#include "Utilities/DebugLog.h"

AEnemyBase::AEnemyBase()
{
	SetGenericTeamId(2);
	Tags.Add(TEXT("Enemy"));
	EnemyClassType = EEnemyClass::Normal;
	EnemyTacticsType = EEnemyType::None;

	AIController = AAIControllerBase::StaticClass();
	AIControllerClass = AIController;

	// Boss 클래스의 적은 위젯을 만들지 않는다.
	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	Widget->SetupAttachment(GetMesh());
	Widget->SetRelativeLocation(FVector(0, 0, 150));
	//Widget->SetRelativeRotation(FRotator(0, 90, 0));
	Widget->SetDrawSize(FVector2D(200, 50));

	ConstructorHelpers::FClassFinder<UEnemyInfoWidget> widget(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/Enemies/WB_EnemyInfo.WB_EnemyInfo_C'"));
	Widget->SetWidgetClass(widget.Class);



}

void AEnemyBase::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AEnemyBase::BeginPlay()
{
	Super::BeginPlay();

	//State->OnEnemyStateTypeChanged.AddDynamic(this, &AEnemyBase::OnEnemyStateChanged);
	if(Widget)
		Widget->InitWidget();
	DebugLog::Print(GetGenericTeamId());
}

void AEnemyBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (Widget)
	{
		FVector cameraLocation = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraLocation();

		FVector widgetLocation = Widget->K2_GetComponentLocation();

		FRotator rotator = UKismetMathLibrary::FindLookAtRotation(widgetLocation, cameraLocation);
		//DebugLog::Print(rotator);
		Widget->SetWorldRotation(rotator);
	}
}

UBehaviorTree* AEnemyBase::GetBehaviorTree()
{
	return BehaviorTree;
}

//UEnemyStateComponent* AEnemyBase::GetEnemyStateComponent()
//{
//	return State;
//}

//UEnemyAnimationComponent* AEnemyBase::GetEnemyAnimationComponent()
//{
//	return Animation;
//}

//void AEnemyBase::OnEnemyStateChanged(EEnemyStateType InPrevType, EEnemyStateType InNewType)
//{
//	//
//}

EEnemyType AEnemyBase::GetEnemyTacticsType()
{
	return EnemyTacticsType;
}

bool AEnemyBase::IsEnemyHasWeaponOnTheType(EWeaponType InWeaponType)
{
	return Weapons.Contains(InWeaponType);
}

TObjectPtr<AWeaponBase> AEnemyBase::GetEnemyWeaponOfWeaponType(EWeaponType InWeaponType)
{
	return Weapons[InWeaponType];
}

void AEnemyBase::SetSenseConfigSight_SightRadius(float InRadius)
{
	Cast<AAIControllerBase>(GetController())->SetSenseConfigSight_SightRadius(InRadius);
}

void AEnemyBase::SetSenseConfigSight_LoseSightRadius(float InRadius)
{
	Cast<AAIControllerBase>(GetController())->SetSenseConfigSight_LoseSightRadius(InRadius);
}

void AEnemyBase::SetActionRange(float InActionRange)
{
	Cast<AAIControllerBase>(GetController())->SetActionRange(InActionRange);
}
