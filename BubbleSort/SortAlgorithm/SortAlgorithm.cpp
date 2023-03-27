#include "SortAlgorithm.h"

SortAlgorithm::SortAlgorithm(const std::string& sortName) : sortName(sortName) {}

const bool SortAlgorithm::isSorted() const
{
	return sortedStatus;
}

const std::string& SortAlgorithm::getSortName() const
{
	return sortName;
}

const int SortAlgorithm::getSwapCount() const
{
	return swapCount;
}

const std::vector<std::pair<const int, const SDL_Color>>& SortAlgorithm::getRectanglesToHighlight() const
{
	return rectanglesToHighlight;
}

void SortAlgorithm::clearRectanglesToHighlight()
{
	rectanglesToHighlight.clear();
}

void SortAlgorithm::setArray(SDL_Rect* rectangleArray)
{
	this->rectangleArray = rectangleArray;
}

void SortAlgorithm::swapRectangles(const int rectOneIndex, const int rectTwoIndex)
{
	int tempY = rectangleArray[rectOneIndex].y, tempH = rectangleArray[rectOneIndex].h;
	rectangleArray[rectOneIndex].y = rectangleArray[rectTwoIndex].y;
	rectangleArray[rectOneIndex].h = rectangleArray[rectTwoIndex].h;
	rectangleArray[rectTwoIndex].y = tempY;
	rectangleArray[rectTwoIndex].h = tempH;
	++swapCount;
}

void SortAlgorithm::setRectanglesToHighlight(const int indexOfRectangle, const SDL_Color& highlightColor)
{
	rectanglesToHighlight.push_back(std::make_pair(indexOfRectangle, highlightColor));
}