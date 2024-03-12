// Fill out your copyright notice in the Description page of Project Settings.


#include "System/EnemySpawner.h"

#include "NavigationSystem.h"
#include "Kismet/KismetMathLibrary.h"

#include "Characters/Enemies/EnemyBase.h"
#include "System/Visualizers/ShapeComponentVisualizer.h"

#include "Utilities/DebugLog.h"

// Sets default values
AEnemySpawner::AEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShapeComponent = CreateDefaultSubobject<UShapeComponentVisualizer>(TEXT("ShapeComponent"));
	
}

// Called when the game starts or when spawned
void AEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	
	EnemySpawn();
}

// Called every frame
void AEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemySpawner::EnemySpawn(int32 InSpawnCount)
{
	if (InSpawnCount == 0)
		InSpawnCount = SpawnCount;

	UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
	for (int32 i = 0; i < InSpawnCount; i++)
	{
		FNavLocation NavLocation;
		FTransform transform;

		NavSystem->GetRandomPointInNavigableRadius(GetActorLocation(), ShapeComponent->Radius, NavLocation);
		transform.SetLocation(NavLocation.Location);

		int32 randIdx = UKismetMathLibrary::RandomIntegerInRange(0, Enemies.Num()-1);
		TObjectPtr<AEnemyBase> Enemy = GetWorld()->SpawnActorDeferred<AEnemyBase>(Enemies[randIdx], transform, nullptr, nullptr, ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

		FVector location = transform.GetLocation();
		location.Z += Enemy->GetDefaultHalfHeight();
		transform.SetLocation(location);

		Enemy->FinishSpawning(transform);
	}
}

