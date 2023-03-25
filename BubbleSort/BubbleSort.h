#pragma once
#include "SortAlgorithm.h"

class BubbleSort final : public SortAlgorithm
{
public:
	BubbleSort();

private:
	void sort(BarChart& barChart) override;
};

