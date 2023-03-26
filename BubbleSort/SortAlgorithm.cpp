#include "SortAlgorithm.h"

const bool SortAlgorithm::isSorted() const
{
	return sortedStatus;
}

const std::string& SortAlgorithm::getSortName() const
{
	return sortName;
}

const std::vector<std::pair<int, SDL_Color>>& SortAlgorithm::getRectanglesToHighlight() const
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

void SortAlgorithm::swapRectangles(const int rectOne, const int rectTwo)
{
	int tempY = rectangleArray[rectOne].y, tempH = rectangleArray[rectOne].h;
	rectangleArray[rectOne].y = rectangleArray[rectTwo].y;
	rectangleArray[rectOne].h = rectangleArray[rectTwo].h;
	rectangleArray[rectTwo].y = tempY;
	rectangleArray[rectTwo].h = tempH;
	++swapCount;
}

void SortAlgorithm::setRectanglesToHighlight(const int indexOfRectangle, const SDL_Color& highlightColor)
{
	rectanglesToHighlight.push_back(std::make_pair(indexOfRectangle, highlightColor));
}