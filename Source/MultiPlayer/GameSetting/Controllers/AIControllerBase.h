#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "AIControllerBase.generated.h"

class UBehaviorTreeComponent;
class UAISenseConfig_Sight;

class AEnemyBase;

UCLASS()
class MULTIPLAYER_API AAIControllerBase : public AAIController
{
	GENERATED_BODY()
	
public :
	AAIControllerBase();

protected :
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	//~ Begin AController Interface
protected:
	/* Pawn �� ���� �Ǿ��� ��� */
	virtual void OnPossess(APawn* InPawn) override;
	/* ���ǰ� ���� �Ǿ��� ��� */
	virtual void OnUnPossess() override;
	//~ End AController Interface

private:
	/* 
	* PerceptionComponent -> OnPerceptionUpdated Delegate
	* AI Sense�� �����ǰų� ���� ���� ���� �� �߻�
	* ������ ������Ʈ�� �߰�
	*/
	UFUNCTION()
		void OnPerceptionUpdated(const TArray<AActor*>& UpdateActors);

public :
	/* Sight Radius�� �����մϴ�. */
	void SetSenseConfigSight_SightRadius(float InRadius);
	/* Lose Sight Radius�� �����մϴ�. */
	void SetSenseConfigSight_LoseSightRadius(float InRadius);
	/* Action Range�� �����մϴ�. */
	void SetActionRange(float InActionRange);


protected:
	/* OwnerEnemy ������ Pawn */
	TObjectPtr<AEnemyBase> OwnerEnemy;
	/* AISenseConfig_Sight ���� Ŭ���� */
	TObjectPtr<UAISenseConfig_Sight> Sight;

private:
	/* AI ���� ���� */
	UPROPERTY(VisibleDefaultsOnly)
		float ActionRange = 150;

	/* ����� */
	UPROPERTY(EditAnywhere)
		bool bDrawDebug = true;
	/* ������ �� ���� ���� */
	UPROPERTY(EditAnywhere)
		float AdjustCircleHeight = 50;

};
