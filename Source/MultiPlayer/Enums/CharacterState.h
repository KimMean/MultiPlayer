#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterState.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	//None,
	Idle,		// 유휴
	Wait,		// 대기
	Move,		// 움직임
	Ambush,		// 기습
	Attack,		// 공격
	Cast,		// 시전
	Defend,		// 방어
	Patrol,		// 순찰
	Chase,		// 추격
	Retreat,	// 후퇴
	Hold,		// 사수
	Hit,		// 피격
	Stun,		// 기절
	Evation,	// 회피
	Death,		// 죽음
};

UENUM(BlueprintType)
enum class EMoveState : uint8
{
	None,
	Walk,
	Jog,
	Run,
};

UCLASS()
class MULTIPLAYER_API UCharacterState : public UObject
{
	GENERATED_BODY()

public:
	UCharacterState();

	static FString ToString(ECharacterState Value);
	static void PrintString(ECharacterState Value, float Time, FColor Color);
};
