#pragma once

#include "SortAlgorithm.h"

class MergeSort : public SortAlgorithm
{
public:
	MergeSort();

private:
	void sort(BarChart& barChart) override;
	int findMin(const int, const int);
	void merge(int l, int m, int r, BarChart& barChart);

	int m = 1, from = 0, mid = 0, to = 0, firstI = 0;
	int low = 0, high = numberOfRectangles - 1, mergeIterator;
	int j, k, i;
	SDL_Rect tempArr[numberOfRectangles];
	bool currentlyMerging = false, mergeStarted = false, mergeIteratorsSet = false, setTemp = true;
};

