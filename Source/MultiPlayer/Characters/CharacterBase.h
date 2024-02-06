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
	/** ������ TeamID�� �� ������Ʈ�� �Ҵ��մϴ�. */
	virtual void SetGenericTeamId(const FGenericTeamId& TeamID) override;

	/** FGenericTeamId �������� �� �ĺ��ڸ� �˻��մϴ�. */
	virtual FGenericTeamId GetGenericTeamId() const override;
	// ~End IGeneric Team Agent Interface

protected :
	/* Generic Team Agent Interface */
	UPROPERTY(VisibleDefaultsOnly, Category = "AI")
		FGenericTeamId GenericTeamID;
};
