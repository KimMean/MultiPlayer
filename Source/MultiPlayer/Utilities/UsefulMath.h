#pragma once

#include "CoreMinimal.h"

class MULTIPLAYER_API UsefulMath
{
public:
	UsefulMath();
	~UsefulMath();

public :
	/* 
	* ����ġ�� ��� �迭�� �ѱ�� �������� ���õ� �ε����� ��ȯ�˴ϴ�.
	* @ TArray<float> InWeights ����ġ�� ��� �迭
	* return 0 ~ InWeights.Num() - 1;
	*/
	static int32 WeightedRandomIndex(TArray<float> InWeights);

	/*
	* ��ġ�� �������� �޾� ���� �� ������ ��ġ�� ��ȯ�մϴ�.
	*/
	static FVector GetRandomLocationWithinRange(FVector InLocation, float InRadius);
};
