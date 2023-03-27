#pragma once

#include "SortAlgorithm.h"

class CocktailShakerSort final : public SortAlgorithm
{
public:
	CocktailShakerSort();
	virtual ~CocktailShakerSort() {};

private:
	bool ascendingSort = true, swapOccurred;
	int maxIndexToSort = numberOfRectangles, minIndexToSort = 0;

	void sort(BarChart& barChart) override;
};