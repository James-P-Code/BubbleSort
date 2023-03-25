#pragma once
#include "SortAlgorithm.h"

class SelectionSort final : public SortAlgorithm
{
public:
	SelectionSort();

private:
	void sort(BarChart& barChart) override;

	int indexOfMinimum;
};

