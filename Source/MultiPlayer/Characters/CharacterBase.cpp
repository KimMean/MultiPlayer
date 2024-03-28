#include "Characters/CharacterBase.h"

#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/CapsuleComponent.h"

#include "Actors/Weapons/WeaponBase.h"
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
	status.HealthPoint = 100;
	CharacterStatus->SetCharacterStatus(status);

	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	//UGameplayStatics::GetGameInstance(GetWorld());
	//Cast<GameInstanceBase> GetWorld()->GetGameInstance()

	CharacterState->CharacterStateChangedDelegate.AddDynamic(this, &ACharacterBase::OnCharacterStateChanged);

	CharacterStatus->OnHealthPointChangedDelegate.BindUObject(this, &ACharacterBase::OnHealthPointChanged);
	// BindUFunction은 UFUNCTION() 이 있어야 한다.
	//CharacterStatus->OnHealthPointChangedDelegate.BindUFunction(this, FName("OnHealthPointChanged"));
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

	AdjustHealthPoint(-Damage);

	if (CharacterStatus->GetCurrentHealthPoint() == 0)
	{
		OnDeath();
	}
	else
	{
		OnHit();
	}

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

void ACharacterBase::OnHealthPointChanged()
{
	DebugLog::Print("OnHealthPointChanged");
}

void ACharacterBase::StatusNotification(ECharacterState InCharacterState)
{
}

void ACharacterBase::PersistentStatusNotification(ECharacterState InCharacterState)
{
}

void ACharacterBase::OnHit()
{
	if (CharacterState->GetIsIdleMode())
		CharacterState->SetHitMode();
}

void ACharacterBase::OnDeath()
{
	CharacterState->SetDeathMode();
	SetCapsuleComponentCollisionEnabled(ECollisionEnabled::NoCollision);
	Animation->StopAnimMontage();
	Animation->PlayAnimMontage(ECharacterState::Death);

	for (TTuple<EWeaponType, TObjectPtr<AWeaponBase>> weapon : Weapons)
	{
		weapon.Value->Destroy();
	}
	Weapons.Empty();
	DebugLog::Print("CharacterBase:Death");
}

void ACharacterBase::SetCapsuleComponentCollisionEnabled(ECollisionEnabled::Type InEnabled)
{
	GetCapsuleComponent()->SetCollisionEnabled(InEnabled);
}

void ACharacterBase::SetVisibility(bool InVisibility)
{
}

void ACharacterBase::SetWeaponCollisionEnable(EWeaponType InWeaponType, bool InEnable)
{
	if(IsCharacterHasWeaponOnTheType(InWeaponType))
		Weapons[InWeaponType]->SetCollisionEnabled(InEnable);
}

bool ACharacterBase::IsCharacterHasWeaponOnTheType(EWeaponType InWeaponType)
{
	return Weapons.Contains(InWeaponType);
}

TObjectPtr<AWeaponBase> ACharacterBase::GetCharacterWeaponOfWeaponType(EWeaponType InWeaponType)
{
	return Weapons[InWeaponType];
}

void ACharacterBase::AdjustHealthPoint(float InAdjustValue)
{
	CharacterStatus->AdjustCurrentHealthPoint(InAdjustValue);
}
