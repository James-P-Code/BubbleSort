#pragma once
#include "SortAlgorithm.h"

class BubbleSort final : public SortAlgorithm
{
public:
	BubbleSort();
	virtual ~BubbleSort() {};

private:
	bool swapOccurred;
	int currentRectangle = 0;

	void sort(BarChart& barChart) override;
};