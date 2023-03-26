#pragma once

#include <stack>
#include "SortAlgorithm.h"

class QuickSort final : public SortAlgorithm
{
public:
	QuickSort();
	virtual ~QuickSort() {};

private:
	std::stack<std::pair<int, int>> qsStack;
	int startIndex = 0, endIndex = numberOfRectangles - 1, pivotIndex, pivotRectY;
	bool newIteration = true;

	void sort(BarChart& barChart) override;
};