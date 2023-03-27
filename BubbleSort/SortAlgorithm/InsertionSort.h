#pragma once
#include "SortAlgorithm.h"

class InsertionSort final : public SortAlgorithm
{
public:
	InsertionSort();
	virtual ~InsertionSort() {};

private:
	SDL_Rect keyRect;
	bool newIteration = true;
	int currentRectangle = 0;

	void sort(BarChart& barChart) override;
};