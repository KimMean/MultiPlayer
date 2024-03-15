
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Interfaces/OnlineSessionInterface.h"
#include "SteamSystem.generated.h"

UCLASS()
class MULTIPLAYER_API USteamSystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	USteamSystem();

public:
	void CreateSession();
	void JoinSession();
	void OnCreateSessionComplate(FName SessionName, bool bWasSuccessful);
	void OnFindSessionComplate(bool bWasSuccessful);
	void OnJoinSessionComplate(FName SessionName, EOnJoinSessionCompleteResult::Type Result);


private:
	IOnlineSessionPtr OnlineSessionInterface;
	TSharedPtr<FOnlineSessionSearch> SessionSearch;
	FOnCreateSessionCompleteDelegate CreateSessionCompleteDelegate;
	FOnFindSessionsCompleteDelegate FindSessionCompleteDelegate;
	FOnJoinSessionCompleteDelegate JoinSessionCompleteDelegate;
};
