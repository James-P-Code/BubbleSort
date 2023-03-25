#pragma once

#include <stack>
#include "SortAlgorithm.h"

class QuickSort : public SortAlgorithm
{
public:
	QuickSort();

private:
	std::stack<std::pair<int, int>> qsStack;
	int startIndex = 0, endIndex = numberOfRectangles - 1, pIndex, pivotRectY;
	bool newIteration = true;

	void sort(BarChart& barChart) override;
};

