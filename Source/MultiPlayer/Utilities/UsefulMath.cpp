#include "Utilities/UsefulMath.h"

UsefulMath::UsefulMath()
{
}

UsefulMath::~UsefulMath()
{
}

int32 UsefulMath::WeightedRandomIndex(TArray<float> InWeights)
{
	float totalWeight = 0.0f;
	// 가중치의 총합 계산
	for (const float weight : InWeights)
	{
		totalWeight += weight;
	}

	// 랜덤한 가중치 값 생성
	float randomWeight = FMath::FRandRange(0.0f, totalWeight);

	// 가중치에 따라 상태 선택
	int32 index = 0;
	float weightSum = 0.0f;
	for (const float weight : InWeights)
	{
		weightSum += weight;
		if (randomWeight <= weightSum)
			return index;
		index++;
	}

	// 예외 상황, -1이 반환되는 경우는 없어야 합니다.
	return -1;
}

FVector UsefulMath::GetRandomLocationWithinRange(FVector InLocation, float InRadius)
{
	float xRange = FMath::FRandRange(-InRadius, InRadius);
	float yRange = FMath::FRandRange(-InRadius, InRadius);

	FVector location = InLocation + (xRange, yRange);
	return location;
}
