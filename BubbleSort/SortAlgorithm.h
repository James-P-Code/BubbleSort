#pragma once

#include "SDL.h"
#include "Constants.h"
#include "BarChart.h"
#include <string>
#include <vector>

/* All of the sorts are done in what I would call an iterative manner.  Because the overall program is driven by a loop
*  in main() the sorts need to be done 1 step at a time.  This is because the window needs to be updated after every step
*  to show the visualization of the sorting.  Every iteration through the main() loop follows a "update -> render" pattern,
*  where a step of a sort is done during the update, and then everything is rendered.    */

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
		CocktailShakerSort = 6,
		RadixSort = 7
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
	std::string sortName;
	bool sortedStatus = false, swapStatus = false;
	int currentRectangle = 0, swapCount = 0, sortIterator = 0;

	void setArray(SDL_Rect* rectangleArray);
	void swapRectangles(const int rectOne, const int rectTwo);
	void setRectanglesToHighlight(const int indexOfRectangle, const SDL_Color& highlightColor);
};