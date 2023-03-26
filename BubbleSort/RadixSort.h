#pragma once

#include "SortAlgorithm.h"

class RadixSort final : public SortAlgorithm
{
public:
	RadixSort();
	virtual ~RadixSort() {};

private:
	static constexpr int base = 10;
	int maxValue = 0, digitPosition = 1;
	int digitCountArray[base] = { 0 };
	SDL_Rect bucket[numberOfRectangles];
	bool countDigitsAtDigitPosition = true, countNumberOfDigits = false, placeBucketInOrder = false, updateMainArray = false;

	void sort(BarChart& barChart) override;
};