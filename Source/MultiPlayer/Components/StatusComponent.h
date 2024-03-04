#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Characters/CharacterInformation.h"
#include "StatusComponent.generated.h"

//FString CharacterName;
//int32 Level;
//float Experience;
//int32 HealthPoint;
//int32 MagicPoint;
//int32 Strength = 10;
//int32 Intelligence = 10;
//int32 PhysicalDef = 10;
//int32 MagicDef = 10;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MULTIPLAYER_API UStatusComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStatusComponent();

protected:
	virtual void BeginPlay() override;

public :
	const FCharacterStatus& GetCharacterStatus();
	void SetCharacterStatus(FCharacterStatus InCharacterStatus);

public:
	/* Increase Character Level */
	//void CharacterLevelUp();
	///* Character Experience + InExperience, curExp > MAX_EXP -> LevelUp */
	//void ModifyExperience(float InExperience);
	//void ModifyHealthPoint(int32 InHealthPoint);
	//void ModifyMagichPoint(int32 InMagichPoint);
	//void ModifyStrength(int32 InStrength);
	//void ModifyIntelligence(int32 InIntelligence);
	//void ModifyPhysicalDefense(int32 InPhysicalDefense);
	//void ModifyMagichDefense(int32 InMagichDefense);

	/* CurrentHealthPoint += InAdjustValue; */
	void AdjustCurrentHealthPoint(float InAdjustValue);

// Get
public :
	const FString GetName();
	const int32 GetLevel();
	const float GetExperience();
	const int32 GetMaxHealthPoint();
	const int32 GetCurrentHealthPoint();
	const int32 GetMaxMagicPoint();
	const int32 GetCurrentMagicPoint();
	const int32 GetStrength();
	const int32 GetIntelligence();
	const int32 GetPhysicalDefense();
	const int32 GetMagicDefense();

// Set
public :
	void SetName(FString InCharacterName);
	void SetLevel(int32 InCharacterLevel);
	void SetExperience(float InCharacterExperience);
	void SetMaxHealthPoint(int32 InCharacterHealthPoint);
	void SetCurrentHealthPoint(int32 InCharacterHealthPoint);
	void SetMaxMagicPoint(int32 InCharacterMagicPoint);
	void SetCurrentMagicPoint(int32 InCharacterMagicPoint);
	void SetStrength(int32 InCharacterStrength);
	void SetIntelligence(int32 InCharacterIntelligence);
	void SetPhysicalDefense(int32 InCharacterPhysicalDefense);
	void SetMagicDefense(int32 InCharacterMagicDefense);


private :
	UPROPERTY(VisibleAnywhere)
		FCharacterStatus CharacterStatus;

	UPROPERTY(EditAnywhere)
		float CurrentHealthPoint;
	UPROPERTY(VisibleAnywhere)
		float CurrentMagicPoint;
};
