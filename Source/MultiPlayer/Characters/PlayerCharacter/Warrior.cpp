#include "Characters/PlayerCharacter/Warrior.h"

#include "Engine/SkeletalMeshSocket.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/AnimationComponent.h"
#include "Animation/AnimInstance.h"

#include "Actors/Weapons/SwordBase.h"
#include "Utilities/DebugLog.h"
AWarrior::AWarrior()
{
	ConstructorHelpers::FObjectFinder<USkeletalMesh> mesh(TEXT("/Script/Engine.SkeletalMesh'/Game/Characters/Pirate/Meshes/SKM_Pirate.SKM_Pirate'"));
	ConstructorHelpers::FClassFinder<UAnimInstance> ABP(TEXT("/Script/Engine.AnimBlueprint'/Game/Blueprints/Characters/Warrior/ABP_Warrior.ABP_Warrior_C'"));

	PlayerClass = EPlayerClass::Warrior;
	GetMesh()->SetAnimClass(ABP.Class);

	if (mesh.Succeeded() == true)
	{
		GetMesh()->SetSkeletalMesh(mesh.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -90));
		GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));
	}

}

void AWarrior::BeginPlay()
{
	Super::BeginPlay();

	CreateWeapon();
}

void AWarrior::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AWarrior::OnAttack()
{
	//DebugLog::Print("OnAttack");

	// 공격모드가 아닐경우 공격
	if(!CharacterState->GetIsAttackMode())
	{
		ComboCount = 0;
		bComboAttack = false;
		CharacterState->SetAttackMode();
		Animation->PlayAnimMontage(ECharacterState::Attack);
	}
	else
	{
		// 공격 중, 연속 공격이 가능, 콤보 공격이 예정되지 않음
		if (bComboEnable && !bComboAttack)
		{
			ComboCount++;
			bComboAttack = true;
		}
	}
}

void AWarrior::ExtraAttack()
{
	if (!bComboAttack) return;

	bComboAttack = false;
	Animation->PlayAnimMontageByIndex(ECharacterState::Attack, ComboCount);

}

void AWarrior::CreateWeapon()
{
	TObjectPtr<UClass> sword = LoadClass<ASwordBase>(NULL, TEXT("/Script/Engine.Blueprint'/Game/Blueprints/Weapons/Swords/BP_SwordBase.BP_SwordBase_C'"));

	const USkeletalMeshSocket* socket = GetMesh()->GetSocketByName("Weapon");
	FTransform transform = socket->GetSocketTransform(GetMesh());

	TObjectPtr<AWeaponBase> weapon = GetWorld()->SpawnActorDeferred<ASwordBase>(sword, transform, this, this, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);
	socket->AttachActor(weapon, GetMesh());
	weapon->FinishSpawning(transform);
	Weapons.Add(EWeaponType::OneHandSword, weapon);

}


