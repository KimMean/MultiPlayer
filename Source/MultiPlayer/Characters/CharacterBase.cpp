#include "Characters/CharacterBase.h"

#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "Components/StateComponent.h"
#include "Components/StatusComponent.h"
#include "Components/AnimationComponent.h"

#include "Utilities/DebugLog.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	SetGenericTeamId(1);

	Animation = CreateDefaultSubobject<UAnimationComponent>(TEXT("AnimationComponent"));
	CharacterState = CreateDefaultSubobject<UStateComponent>(TEXT("StateComponent"));
	CharacterStatus = CreateDefaultSubobject<UStatusComponent>(TEXT("StatusComponent"));

	FCharacterStatus status;
	status.HealthPoint = 10000;
	CharacterStatus->SetCharacterStatus(status);

	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	CharacterState->CharacterStateChangedDelegate.AddDynamic(this, &ACharacterBase::OnCharacterStateChanged);
}

void ACharacterBase::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

}


//void ACharacterBase::SetCharacterState(ECharacterState InState)
//{
//	ECharacterState type = CharacterState;
//	CharacterState = InState;
//
//	if (OnCharacterStateTypeChanged.IsBound())
//	{
//		OnCharacterStateTypeChanged.Broadcast(type, CharacterState);
//	}
//}

const TObjectPtr<UStateComponent> ACharacterBase::GetCharacterStateComponent() const
{
	return CharacterState;
}

const TObjectPtr<UStatusComponent> ACharacterBase::GetCharacterStatusComponent() const
{
	return CharacterStatus;
}

UAnimationComponent* ACharacterBase::GetAnimationComponent()
{
	return Animation;
}

float ACharacterBase::TakeDamage(float Damage, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (CharacterState->GetIsDeathMode()) return 0;

	CharacterStatus->AdjustCurrentHealthPoint(-Damage);

	if (CharacterStatus->GetCurrentHealthPoint() == 0)
		CharacterState->SetDeathMode();

	return Damage;
}

void ACharacterBase::SetGenericTeamId(const FGenericTeamId& TeamID)
{
	GenericTeamID = TeamID;
}

FGenericTeamId ACharacterBase::GetGenericTeamId() const
{
	return GenericTeamID;
}

void ACharacterBase::OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState)
{
	//DebugLog::Print(InNewState) 
	//DebugLog::Print(UCharacterState::ToString(InNewState));
}

void ACharacterBase::AbilityActivation(ECharacterState InCharacterState)
{
}

void ACharacterBase::MaintainAbility(ECharacterState InCharacterState)
{
}
