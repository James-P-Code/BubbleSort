#pragma once

#include "SDL.h"
#include "../Constants.h"
#include "../BarChart/BarChart.h"
#include <string>
#include <vector>

/* All of the sorts are done in what I would call an iterative manner.  Because the overall program is driven by a loop
*  in main() the sorts need to be done 1 step at a time.  This is because the window needs to be updated after every step
*  to show the visualization of the sorting.  Every iteration through the main() loop follows a "update -> render" pattern,
*  where a step of a sort is done during the update, and then everything is rendered.    */

class SortAlgorithm
{
public:
	virtual ~SortAlgorithm() {};
	virtual void sort(BarChart& barChart) = 0;
	const bool isSorted() const;
	const std::string& getSortName() const;
	const int getSwapCount() const;
	const std::vector<std::pair<const int, const SDL_Color>>& getRectanglesToHighlight() const;
	void clearRectanglesToHighlight();

	enum class SortType
	{
		None,
		BubbleSort,
		SelectionSort,
		InsertionSort,
		QuickSort,
		MergeSort,
		CocktailShakerSort,
		RadixSort
	};

protected:
	static constexpr SDL_Color greenHighlightColor = { 66, 245, 72, 255 };
	static constexpr SDL_Color redHighlightColor = { 230, 11, 11, 255 };
	const std::string sortName;
	SDL_Rect* rectangleArray = nullptr;
	std::vector<std::pair<const int, const SDL_Color>> rectanglesToHighlight;
	bool sortedStatus = false;
	int  swapCount = 0, sortIterator = 0;

	SortAlgorithm(const std::string& sortName);
	void setArray(SDL_Rect* rectangleArray);
	void swapRectangles(const int rectOneIndex, const int rectTwoIndex);
	void setRectanglesToHighlight(const int indexOfRectangle, const SDL_Color& highlightColor);
};