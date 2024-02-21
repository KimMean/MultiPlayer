#include "Characters/PlayerCharacter/PlayerAnimInstance.h"

#include "Characters/PlayerCharacter/PlayerBase.h"
#include "Utilities/DebugLog.h"


UPlayerAnimInstance::UPlayerAnimInstance()
{
}

void UPlayerAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Character = Cast<APlayerBase>(Character);
	if (Character.IsValid() == false) return;

}

void UPlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
	if (Character.IsValid() == false) return;


}
