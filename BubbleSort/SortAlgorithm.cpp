#include "SortAlgorithm.h"

void SortAlgorithm::bubbleSort(BarChart& barChart)
{
	swapStatus = false;

	if (!rectangleArray)
	{
		rectangleArray = barChart.getChart().data();
	}

	if (sortIterator < numberOfRectangles)
	{
		if (currentRectangle < numberOfRectangles - sortIterator - 1)
		{
			if (rectangleArray[currentRectangle].y < rectangleArray[currentRectangle + 1].y)
			{
				int tempY = rectangleArray[currentRectangle].y, tempH = rectangleArray[currentRectangle].h;
				rectangleArray[currentRectangle].y = rectangleArray[currentRectangle + 1].y;
				rectangleArray[currentRectangle].h = rectangleArray[currentRectangle + 1].h;
				rectangleArray[currentRectangle + 1].y = tempY;
				rectangleArray[currentRectangle + 1].h = tempH;
				swapStatus = true;
				barChart.updateSwapCount(++swapCount);
			}
			currentRectangle++;
		}
		else
		{
			currentRectangle = 0;
			sortIterator++;
			swapStatus = false;
		}
	}

	if (sortIterator == numberOfRectangles)
	{
		sortStatus = true;
	}
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