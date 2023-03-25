#pragma once

#include <stack>
#include "SortAlgorithm.h"
#include <iostream>

class QuickSort : public SortAlgorithm
{
public:
	QuickSort();

private:
	std::stack<std::pair<int, int>> qsStack;
	int startIndex = 0, endIndex = numberOfRectangles - 1, pivot, pIndex;
	bool newIteration = true;
	SDL_Rect pivotRect;

	void sort(BarChart& barChart) override;
};

