#pragma once

#include "SDL.h"
#include "Constants.h"
#include "BarChart.h"

class SortAlgorithm final
{
public:
	enum class SortType
	{
		BubbleSort = 1,
		SelectionSort = 2
	};

	void sort(SortAlgorithm::SortType& sortType, BarChart& barChart);
	const bool isSorted() const;
	const bool swapOccurred() const;
	const int getCurrentRectangle() const;

private:
	int currentRectangle = 0, sortIterator = 0, swapCount = 0, indexOfMinimum = 0;
	bool swapStatus, sortStatus = false;
	SDL_Rect* rectangleArray = nullptr;

	void bubbleSort(BarChart& barChart);
	void selectionSort(BarChart& barChart);
};

