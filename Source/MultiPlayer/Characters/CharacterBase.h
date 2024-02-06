#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "CharacterBase.generated.h"


UCLASS()
class MULTIPLAYER_API ACharacterBase : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	ACharacterBase();

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

public :
	// ~Begin IGeneric Team Agent Interface
	/** 지정된 TeamID에 팀 에이전트를 할당합니다. */
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;

	/** FGenericTeamId 형식으로 팀 식별자를 검색합니다. */
	virtual FGenericTeamId GetGenericTeamId() const override;
	// ~End IGeneric Team Agent Interface

protected :
	/* Generic Team Agent Interface */
	UPROPERTY(VisibleDefaultsOnly, Category = "AI")
		FGenericTeamId GenericTeamID;
};
