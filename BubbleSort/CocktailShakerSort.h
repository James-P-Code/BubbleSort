#pragma once

#include "SortAlgorithm.h"

class CocktailShakerSort : public SortAlgorithm
{
public:
	CocktailShakerSort();

private:
	void sort(BarChart& barChart) override;
	bool ascendingSort = true;
	int maxIndexToSort = numberOfRectangles, minIndexToSort = 0;
};

