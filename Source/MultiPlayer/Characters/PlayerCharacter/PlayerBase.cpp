#include "Characters/PlayerCharacter/PlayerBase.h"

#include "Kismet/GameplayStatics.h"
#include "GameFramework/SpringArmComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputMappingContext.h"
#include "Camera/CameraComponent.h"
//#include "Blueprint/UserWidget.h"

#include "Components/AnimationComponent.h"
#include "UserInterface/Player/GameUI.h"

#include "Utilities/DebugLog.h"

APlayerBase::APlayerBase()
{
	Tags.Add(TEXT("Player"));

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	//HPWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthWidget"));

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));

	if (mesh.Succeeded() == true)
	{
		GetMesh()->SetSkeletalMesh(mesh.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
	}

	SpringArm->SetupAttachment(RootComponent);
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 300.0f;
	SpringArm->SocketOffset.Z = 150.0f;
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritRoll = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bDoCollisionTest = true;

	Camera->AddRelativeRotation(FRotator(-10.0f, 0.0f, 0.0f));

	bUseControllerRotationYaw = true;

	ConstructorHelpers::FClassFinder<UGameUI> ui(TEXT("/Script/UMGEditor.WidgetBlueprint'/Game/UI/Player/WB_InGame.WB_InGame_C'"));
	GameWidgetClass = ui.Class;
}

void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* PlayerController = Cast<APlayerController>(Controller);
	if (PlayerController != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem< UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer());
		if (Subsystem != nullptr)
		{
			Subsystem->AddMappingContext(InputMapping, 0);
			DebugLog::Print("AddMappingContext");
		}
	}
	
	GameWidget = CreateWidget<UGameUI>(GetController<APlayerController>(), GameWidgetClass);
	if (GameWidget)
	{
		GameWidget->Initialize();
		GameWidget->AddToViewport();
		GameWidget->ModifyHealthPointPercent(1.0f);
	}
}

void APlayerBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}

void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (input == nullptr) return;

	input->BindAction(InputActions.FindRef("Move"), ETriggerEvent::Triggered, this, &APlayerBase::OnMove);
	input->BindAction(InputActions.FindRef("MousePosition"), ETriggerEvent::Triggered, this, &APlayerBase::OnLook);
	input->BindAction(InputActions.FindRef("LMB_Attack"), ETriggerEvent::Triggered, this, &APlayerBase::OnAttack_LMB);
	input->BindAction(InputActions.FindRef("RMB_Attack"), ETriggerEvent::Triggered, this, &APlayerBase::OnAttack_RMB);

	DebugLog::Print("SetupPlayerInputComponent");
}

void APlayerBase::OnMove(const FInputActionInstance& Instance)
{
	//DebugLog::Print(Instance.GetValue().Get<FVector2D>());
	if (!bMoveable) return;

	FVector2D moveDirection = Instance.GetValue().Get<FVector2D>();

	AddMovementInput(GetActorRightVector(), moveDirection.X);
	AddMovementInput(GetActorForwardVector(), moveDirection.Y);
}

void APlayerBase::OnLook(const FInputActionInstance& Instance)
{
	//DebugLog::Print(Instance.GetValue().Get<FVector2D>());

	FVector2D MouseDirection = Instance.GetValue().Get<FVector2D>();

	AddControllerYawInput(MouseDirection.X);
	AddControllerPitchInput(MouseDirection.Y);
}

void APlayerBase::OnAttack_LMB(const FInputActionInstance& Instance)
{
	OnAttack();
}

void APlayerBase::OnAttack_RMB(const FInputActionInstance& Instance)
{
}


void APlayerBase::SetComboEnable(bool InActivate)
{
	bComboEnable = InActivate;
}

void APlayerBase::IncreaseComboCount()
{
	//ComboCount++;
}

void APlayerBase::OnAttack()
{
	// Empty
}

void APlayerBase::OnHit()
{
	Super::OnHit();
	if (CharacterState->GetIsHitMode())
		Animation->PlayAnimMontage(ECharacterState::Hit);
}

void APlayerBase::ExtraAttack()
{
	// Empty
}

void APlayerBase::OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState)
{
	Super::OnCharacterStateChanged(InPrevState, InNewState);

	switch (InNewState)
	{
	case ECharacterState::Idle:
		bMoveable = true;
		break;
	case ECharacterState::Wait:
		break;
	case ECharacterState::Move:
		break;
	case ECharacterState::Attack:
		bMoveable = false;
		break;
	case ECharacterState::Defend:
		break;
	case ECharacterState::Patrol:
		break;
	case ECharacterState::Chase:
		break;
	case ECharacterState::Hold:
		break;
	case ECharacterState::Hit:
		break;
	case ECharacterState::Evation:
		break;
	case ECharacterState::Death:
		break;
	default:
		break;
	}
}

void APlayerBase::OnHealthPointChanged()
{
	Super::OnHealthPointChanged();
	GameWidget->ModifyHealthPointPercent(CharacterStatus->GetCurrentHealthPoint(), CharacterStatus->GetMaxHealthPoint());
}


