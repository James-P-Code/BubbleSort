#pragma once

#include "SortAlgorithm.h"
#include <iostream>

class RadixSort : public SortAlgorithm
{
public:
	RadixSort();

private:
	static constexpr int base = 10;
	int maxValue = 0, digitPosition = 1, countIterator = 0;
	int digitCountArray[base] = { 0 };
	SDL_Rect bucket[numberOfRectangles];
	bool countDigitsAtDigitPosition = true, countNumberOfDigits = false, keepOrder = false, updateMainArray = false;

	void sort(BarChart& barChart) override;
	
};