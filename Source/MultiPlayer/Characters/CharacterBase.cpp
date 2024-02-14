#include "Characters/CharacterBase.h"
#include "Kismet/KismetMathLibrary.h"

#include "Utilities/DebugLog.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	CharacterState = ECharacterState::Idle;
}

void ACharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	FString str = L"";
	str = L"CharacterState : " + UCharacterState::ToString(CharacterState.GetValue());
	str += L"\nHitDirection : " + UDirectionState::ToString(HitDirection.GetValue());
	str += L"\nSaveHit : ";
	str += bSaveHit == true ? L"Ture" : L"False";
	DebugLog::Print(str, -1, 0.01f, FColor::Purple);
}

void ACharacterBase::StopMove()
{
	//GetCharacterMovement()->StopMovementImmediately();
	//GetCharacterMovement()->DisableMovement();
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_None);
}

void ACharacterBase::ResumeMove()
{
	GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Walking);
}

const bool ACharacterBase::GetDamage(const int32 Damage, const EAttackType Type, const FVector OtherLocation, const FHitResult& SweepResult)
{
	if (Type == EAttackType::Physical)
	{
		CurStatus.HealthPoint = CurStatus.HealthPoint - (Damage - CurStatus.PhysicalDef);
	}

	else if (Type == EAttackType::Magic)
	{
		CurStatus.HealthPoint = CurStatus.HealthPoint - (Damage - CurStatus.MagicDef);
	}

	if (CurStatus.HealthPoint <= 0)
	{
		CharacterState = ECharacterState::Death;
		GetController()->UnPossess();
		return true;
	}

	if (CharacterState == ECharacterState::Hit)
		bSaveHit = true;

	CharacterState = ECharacterState::Hit;

	// Hit Direction
	{
		FString debug = L"";

		//FVector direction = GetActorLocation() - SweepResult.TraceStart;
		FVector direction = OtherLocation - GetActorLocation();
		FVector forward = GetActorForwardVector();
		direction.Normalize();
		//forward.Normalize();

		float hitAngle = FMath::Atan2(direction.Y, direction.X);
		hitAngle = FMath::RadiansToDegrees(hitAngle);
		hitAngle += 180.0f;

		float angle = FMath::Atan2(forward.Y, forward.X);
		angle = FMath::RadiansToDegrees(angle);
		angle += 180.0f;
		angle = hitAngle - angle;

		if (angle < 0.0f)
			angle += 360.0f;

		if (angle < 45.0f || angle > 315.0f)
			HitDirection = EDirectionState::Front;
		else if (angle >= 45.0f && angle <= 135.0f)
			HitDirection = EDirectionState::Right;
		else if (angle > 135.0f && angle < 225.0f)
			HitDirection = EDirectionState::Back;
		else if (angle >= 225.0f || angle <= 315.0f)
			HitDirection = EDirectionState::Left;

		debug += L"\nImpacePoint : " + SweepResult.ImpactPoint.ToString();
		debug += L"\nImpaceLocation : " + SweepResult.Location.ToString();
		debug += L"\nImpactNormal : " + SweepResult.ImpactNormal.ToString();
		debug += L"\nOtherLocation : " + OtherLocation.ToString();
		debug += L"\nTraceStart : " + SweepResult.TraceStart.ToString();
		debug += L"\nHitAngle : " + FString::SanitizeFloat(hitAngle);
		debug += L"\nLocal HitAngle : " + FString::SanitizeFloat(angle);
		debug += L"\nHitDirection : " + UDirectionState::ToString(HitDirection);
		DebugLog::Print(debug, -1, 10.0f, FColor::Yellow);

		DebugLog::DrawCapsule(GetWorld(), SweepResult.TraceStart, 30.0f, 30.0f, FColor::Green, false, 10.0f);
		DebugLog::DrawCapsule(GetWorld(), SweepResult.Location, 30.0f, 30.0f, FColor::Yellow, false, 10.0f);
		DebugLog::DrawCapsule(GetWorld(), SweepResult.ImpactPoint, 30.0f, 30.0f, FColor::Red, false, 10.0f);
	}

	return false;
}

void ACharacterBase::ResetState()
{
	CharacterState = ECharacterState::Idle;
	HitDirection = EDirectionState::None;
}

void ACharacterBase::ResetHitState()
{
	CharacterState = ECharacterState::Idle;
	HitDirection = EDirectionState::None;
}
