#pragma once

#include "CoreMinimal.h"

class MULTIPLAYER_API UsefulMath
{
public:
	UsefulMath();
	~UsefulMath();

public :
	/* 
	* 가중치가 담긴 배열을 넘기면 무작위로 선택된 인덱스가 반환됩니다.
	* @ TArray<float> InWeights 가중치가 담긴 배열
	* return 0 ~ InWeights.Num() - 1;
	*/
	static int32 WeightedRandomIndex(TArray<float> InWeights);

	/*
	* 위치와 반지름을 받아 범위 내 무작위 위치를 반환합니다.
	*/
	static FVector GetRandomLocationWithinRange(FVector InLocation, float InRadius);
};
