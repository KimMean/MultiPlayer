#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Enums/CharacterState.h"
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


protected:
	//~ Begin AController Interface
	/* Pawn 에 빙의 되었을 경우 */
	virtual void OnPossess(APawn* InPawn) override;
	/* 빙의가 해제 되었을 경우 */
	virtual void OnUnPossess() override;
	//~ End AController Interface

private:
	/* 
	* PerceptionComponent -> OnPerceptionUpdated Delegate
	* AI Sense에 감지되거나 감지 되지 않을 때 발생
	* 감지된 오브젝트를 추가
	*/
	UFUNCTION()
		void OnPerceptionUpdated(const TArray<AActor*>& UpdateActors);

public :
	/* return Target in Blackboard */
	const TObjectPtr<AActor> GetTargetActor();

	/* Sight Radius를 설정합니다. */
	float GetSenseConfigSight_SightRadius();
	void SetSenseConfigSight_SightRadius(float InRadius);
	/* Lose Sight Radius를 설정합니다. */
	void SetSenseConfigSight_LoseSightRadius(float InRadius);
	/* Action Range를 설정합니다. */
	float GetActionRange();
	void SetActionRange(float InActionRange);

	//void SetBlackboardTarget(ACharacter)

public :
	UFUNCTION()
		virtual void OnCharacterStateChanged(ECharacterState InPrevState, ECharacterState InNewState);

public :
	UFUNCTION(Exec)
		void EnableDebugDrawing(bool InActive);

protected:
	/* OwnerEnemy 빙의한 Pawn */
	TObjectPtr<AEnemyBase> OwnerEnemy;
	/* AISenseConfig_Sight 감지 클래스 */
	TObjectPtr<UAISenseConfig_Sight> Sight;

	/*
	* AIController Interface Blackboard
	* TObjectPtr<UAIPerceptionComponent> PerceptionComponent;
	*/

	/*
	* AIController Interface Blackboard
	* TObjectPtr<UBlackboardComponent> Blackboard;
	*/

private:
	/* AI 공격 범위 */
	UPROPERTY(VisibleDefaultsOnly)
		float ActionRange = 150;

	/* 디버깅 */
	UPROPERTY(EditAnywhere)
		bool bDrawDebug = true;
	/* 디버깅용 원 높이 조절 */
	UPROPERTY(EditAnywhere)
		float AdjustCircleHeight = 50;

};
