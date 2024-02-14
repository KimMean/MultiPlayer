#include "Characters/PlayerCharacter/PlayerBase.h"

#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"

#include "Actors/Weapons/WeaponBase.h"

#include "Utilities/DebugLog.h"

APlayerBase::APlayerBase()
{
	PrimaryActorTick.bCanEverTick = true;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("SkeletalMesh'/Game/Characters/Mannequins/Meshes/SKM_Manny.SKM_Manny'"));

	if (mesh.Succeeded() == true)
	{
		GetMesh()->SetSkeletalMesh(mesh.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
		GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	}

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	{
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
	}
}

void APlayerBase::BeginPlay()
{
	Super::BeginPlay();

	if (Weapon != nullptr)
	{
		Weapon->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, "pelvis");
		
		Weapon->SetOwner(this);
	}
}

void APlayerBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	UDirectionState::PrintString(MoveDirection, 0.01f, FColor::Purple);
	UCharacterState::PrintString(CharacterState, 0.01f, FColor::Cyan);

	FString str;
	str = "MaxWalkSpeed : " + FString::SanitizeFloat(GetCharacterMovement()->MaxWalkSpeed);
	DebugLog::Print(str, -1, 0.01f, FColor::Green);
}

void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	UEnhancedInputComponent* input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (input == nullptr) return;

	input->BindAction(InputActions.FindRef("ForwardMove"), ETriggerEvent::Triggered, this, &APlayerBase::OnForwardMove);
	input->BindAction(InputActions.FindRef("RightMove"), ETriggerEvent::Triggered, this, &APlayerBase::OnRightMove);

	input->BindAction(InputActions.FindRef("ForwardMove"), ETriggerEvent::Completed, this, &APlayerBase::EndForwardMove);
	input->BindAction(InputActions.FindRef("RightMove"), ETriggerEvent::Completed, this, &APlayerBase::EndRightMove);

	input->BindAction(InputActions.FindRef("VerticalLook"), ETriggerEvent::Triggered, this, &APlayerBase::VerticalLook);
	input->BindAction(InputActions.FindRef("HorizontalLook"), ETriggerEvent::Triggered, this, &APlayerBase::HorizontalLook);

	input->BindAction(InputActions.FindRef("LeftClick"), ETriggerEvent::Started, this, &APlayerBase::OnLeftClick);
	input->BindAction(InputActions.FindRef("RightClick"), ETriggerEvent::Started, this, &APlayerBase::OnRightClick);

	input->BindAction(InputActions.FindRef("Evation"), ETriggerEvent::Started, this, &APlayerBase::OnEvation);
}

//void APlayerBase::OnMoveForward(float InAxis)
//{
//	FVector direction = UKismetMathLibrary::GetForwardVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f));
//	AddMovementInput(direction, InAxis);
//}
//
//void APlayerBase::OnMoveRight(float InAxis)
//{
//	FVector direction = UKismetMathLibrary::GetRightVector(FRotator(0.0f, GetControlRotation().Yaw, 0.0f));
//	AddMovementInput(direction, InAxis);
//}

void APlayerBase::OnForwardMove(const FInputActionInstance& Instance)
{
	if (bMoveable == false) return;

	FVector value = Instance.GetValue().Get<FVector>();
	FVector forward = GetActorForwardVector();

	if (value.X > 0.0f)
		MoveDirection = EDirectionState::Front;
	else if (value.X < 0.0f)
		MoveDirection = EDirectionState::Back;
	
	AddMovementInput(forward * value.X);

	CharacterState = ECharacterState::Move;
}

void APlayerBase::OnRightMove(const FInputActionInstance& Instance)
{
	if (bMoveable == false) return;

	FVector value = Instance.GetValue().Get<FVector>();	
	FVector right = GetActorRightVector();

	// Right
	if (value.X > 0.0f)
	{
		if (MoveDirection == EDirectionState::Front)
			MoveDirection = EDirectionState::FrontRight;
		else if (MoveDirection == EDirectionState::Back)
			MoveDirection = EDirectionState::BackRight;
		else
			MoveDirection = EDirectionState::Right;
	}

	// Left
	else if (value.X < 0.0f)
	{
		if (MoveDirection == EDirectionState::Front)
			MoveDirection = EDirectionState::FrontLeft;
		else if (MoveDirection == EDirectionState::Back)
			MoveDirection = EDirectionState::BackLeft;
		else
			MoveDirection = EDirectionState::Left;
	}

	AddMovementInput(right * value.X);

	CharacterState = ECharacterState::Move;
}

void APlayerBase::EndForwardMove(const FInputActionInstance& Instance)
{
	MoveDirection = EDirectionState::None;
	CharacterState = ECharacterState::Idle;
}

void APlayerBase::EndRightMove(const FInputActionInstance& Instance)
{
	if(MoveDirection == EDirectionState::Left ||
		MoveDirection == EDirectionState::Right)
	{
		MoveDirection = EDirectionState::None;
		CharacterState = ECharacterState::Idle;
	}
}

void APlayerBase::VerticalLook(const FInputActionInstance& Instance)
{
	FVector value = Instance.GetValue().Get<FVector>();
	float pitch = VerticalLookRate * value.X * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());

	FString debug = L"";
	debug = L"Vertical value : " + FString::SanitizeFloat(pitch);

	DebugLog::Print(debug, -1, 0.01f, FColor::Red);

	AddControllerPitchInput(pitch);
}

void APlayerBase::HorizontalLook(const FInputActionInstance& Instance)
{
	FVector value = Instance.GetValue().Get<FVector>();
	float yaw = HorizontalLookRate * value.X * UGameplayStatics::GetWorldDeltaSeconds(GetWorld());

	FString debug = L"";
	debug = L"Horizontal value : " + FString::SanitizeFloat(yaw);

	DebugLog::Print(debug, -1, 0.01f, FColor::Red);

	AddControllerYawInput(yaw);
}

void APlayerBase::OnLeftClick(const FInputActionInstance& Instance)
{
	OnAttacking();
}

void APlayerBase::OnRightClick(const FInputActionInstance& Instance)
{
	OnSmashing();
}

void APlayerBase::OnEvation(const FInputActionInstance& Instance)
{
	if (bMoveable == false) return;
	if (bEvation == true) return;
	
	bEvation = true;
	bMoveable = false;
	CharacterState = ECharacterState::Evation;

	/**
	* Evation ÄðÅ¸ÀÓ Ãß°¡
	*/
}

void APlayerBase::OnAttacking()
{
	if (bCanAttack == false) return;

	if (bAttacking == true)
	{
		bSaveAttack = true;
		return;
	}

	if (AttackCombo == MAX_ATTACK_COMBO) return;

	bAttacking = true;
	AttackCombo++;

	CharacterState = ECharacterState::Attack;
}

void APlayerBase::OnSmashing()
{
	if (bCanAttack == false) return;
}

void APlayerBase::ResetEvation()
{
	bEvation = false;
	bMoveable = true;
	CharacterState = ECharacterState::Idle;
}

const bool APlayerBase::SaveAttack()
{
	if (bSaveAttack == true)
	{
		bAttacking = false;
		bSaveAttack = false;
		OnAttacking();

		return true;
	}

	return false;
}

void APlayerBase::ResetAttackState()
{
	bAttacking = false;
	bSmashing = false;
	bSaveAttack = false;
	bSaveSmash = false;

	AttackCombo = 0;

	if (CharacterState != ECharacterState::Death)
		CharacterState = ECharacterState::Idle;
}

void APlayerBase::ResetState()
{
	Super::ResetState();

	MoveDirection = EDirectionState::None;
	bEvation = false;
	bMoveable = true;
}

void APlayerBase::ResetHitState()
{
	Super::ResetHitState();

	bMoveable = true;
}

const bool APlayerBase::GetDamage(const int32 Damage, const EAttackType Type, const FVector OtherLocation, const FHitResult& SweepResult)
{
	bool result = Super::GetDamage(Damage, Type, OtherLocation, SweepResult);

	bMoveable = false;

	return result;
}
