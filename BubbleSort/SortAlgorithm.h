#pragma once

#include "SDL.h"
#include "Constants.h"
#include "BarChart.h"
#include <string>
#include <vector>

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
		QuickSort = 4,
		MergeSort = 5,
		CocktailShakerSort = 6
	};

	virtual void sort(BarChart& barChart) = 0;
	const bool isSorted() const;
	const std::string& getSortName() const;
	const std::vector<std::pair<int, SDL_Color>>& getRectanglesToHighlight() const;
	void clearRectanglesToHighlight();

protected:
	static constexpr SDL_Color greenHighlightColor = { 66, 245, 72, 255 };
	static constexpr SDL_Color redHighlightColor = { 230, 11, 11, 255 };
	SDL_Rect* rectangleArray = nullptr;
	std::vector<std::pair<int, SDL_Color>> rectanglesToHighlight;
	bool sortStatus = false, swapStatus = false;
	int currentRectangle = 0, swapCount = 0, sortIterator = 0;
	std::string sortName;

	void setArray(SDL_Rect* rectangleArray);
	void swapRectangles(const int rectOne, const int rectTwo);
	void setRectanglesToHighlight(const int indexOfRectangle, const SDL_Color& highlightColor);
};