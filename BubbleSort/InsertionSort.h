#pragma once
#include "SortAlgorithm.h"

class InsertionSort final : public SortAlgorithm
{
public:
	InsertionSort();

private:
	SDL_Rect keyRect;
	bool newIteration = true;

	void sort(BarChart& barChart) override;
};