#pragma once

#include "SDL.h"
#include "Constants.h"
#include "BarChart.h"
#include <string>

class BarChart;

class SortAlgorithm
{
public:
	enum class SortType
	{
		None = 0,
		BubbleSort = 1,
		SelectionSort = 2,
		InsertionSort = 3,
		QuickSort = 4
	};

	virtual void sort(BarChart& barChart) = 0;
	const bool isSorted() const;
	const bool swapOccurred() const;
	const int getCurrentRectangle() const;
	const std::string& getSortName() const;

protected:
	SDL_Rect* rectangleArray = nullptr;
	bool sortStatus = false, swapStatus = false;
	int currentRectangle = 0, swapCount = 0, sortIterator = 0;
	std::string sortName;

	void setArray(SDL_Rect* rectangleArray);
	void swapRectangles(const int rectOne, const int rectTwo);
};