#include "SortAlgorithm.h"

void SortAlgorithm::setArray(SDL_Rect* rectangleArray)
{
	this->rectangleArray = rectangleArray;
}

const bool SortAlgorithm::isSorted() const
{
	return sortStatus;
}

const bool SortAlgorithm::swapOccurred() const
{
	return swapStatus;
}

const int SortAlgorithm::getCurrentRectangle() const
{
	return currentRectangle;
}

const std::string& SortAlgorithm::getSortName() const
{
	return sortName;
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