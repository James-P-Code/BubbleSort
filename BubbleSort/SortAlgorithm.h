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
		SelectionSort = 2,
		InsertionSort = 3
	};

	void sort(SortAlgorithm::SortType& sortType, BarChart& barChart);
	const bool isSorted() const;
	const bool swapOccurred() const;
	const int getCurrentRectangle() const;
	const std::string& getSortName() const;

private:
	int currentRectangle = 0, sortIterator = 0, swapCount = 0, indexOfMinimum = 0, keyValue = 0;
	bool swapStatus, sortStatus = false, newIteration = true;
	std::string sortName;
	SDL_Rect* rectangleArray = nullptr;
	SDL_Rect keyRect;

	void bubbleSort(BarChart& barChart);
	void selectionSort(BarChart& barChart);
	void insertionSort(BarChart& barChart);
	void swapRectangles(const int rectOne, const int rectTwo);
};

