#pragma once

#include "SortAlgorithm.h"

class MergeSort final : public SortAlgorithm
{
public:
	MergeSort();
	virtual ~MergeSort() {};

private:
	void sort(BarChart& barChart) override;
	int findMin(const int, const int);
	void merge(int l, int m, int r, BarChart& barChart);

	//  TODO: Clean this up
	int m = 1, from = 0, mid = 0, to = 0, firstI = 0;
	int low = 0, high = numberOfRectangles - 1, mergeIterator = 0;
	int i = 0, j = 0, k = 0;
	SDL_Rect tempArr[numberOfRectangles] = { NULL };
	bool currentlyMerging = false, mergeStarted = false, mergeIteratorsSet = false, setTemp = true;
};