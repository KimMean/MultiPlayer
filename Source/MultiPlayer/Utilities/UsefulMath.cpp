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
	// ����ġ�� ���� ���
	for (const float weight : InWeights)
	{
		totalWeight += weight;
	}

	// ������ ����ġ �� ����
	float randomWeight = FMath::FRandRange(0.0f, totalWeight);

	// ����ġ�� ���� ���� ����
	int32 index = 0;
	float weightSum = 0.0f;
	for (const float weight : InWeights)
	{
		weightSum += weight;
		if (randomWeight <= weightSum)
			return index;
		index++;
	}

	// ���� ��Ȳ, -1�� ��ȯ�Ǵ� ���� ����� �մϴ�.
	return -1;
}

FVector UsefulMath::GetRandomLocationWithinRange(FVector InLocation, float InRadius)
{
	float xRange = FMath::FRandRange(-InRadius, InRadius);
	float yRange = FMath::FRandRange(-InRadius, InRadius);

	FVector location = InLocation + (xRange, yRange);
	return location;
}
