#pragma once

#include "SortAlgorithm.h"

class CocktailShakerSort final : public SortAlgorithm
{
public:
	CocktailShakerSort();
	virtual ~CocktailShakerSort() {};

private:
	void sort(BarChart& barChart) override;
	bool ascendingSort = true;
	int maxIndexToSort = numberOfRectangles, minIndexToSort = 0;
};