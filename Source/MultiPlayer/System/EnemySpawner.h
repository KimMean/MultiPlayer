// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemySpawner.generated.h"

class AEnemyBase;
class UShapeComponentVisualizer;

UCLASS()
class MULTIPLAYER_API AEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void EnemySpawn(int32 InSpawnCount = 0);

protected :
	UPROPERTY(VisibleAnywhere, Category = "ShapeProperty")
		TObjectPtr<UShapeComponentVisualizer> ShapeComponent;

	UPROPERTY(EditAnywhere, Category = "SpawnEnemies")
		TArray<TSubclassOf<AEnemyBase>> Enemies;

	UPROPERTY(EditAnywhere, Category = "SpawnEnemies")
		int32 SpawnCount;

	TArray<AEnemyBase*> SpawnEnemies;
};
