#include "SortAlgorithm.h"

void SortAlgorithm::sort(SortAlgorithm::SortType& sortType, BarChart& barChart)
{
	if (!rectangleArray)
	{
		rectangleArray = barChart.getChart().data();
	}

	switch (sortType)
	{
		case SortType::BubbleSort:
			bubbleSort(barChart);
			break;
		case SortType::SelectionSort:
			selectionSort(barChart);
			break;
	}
}

void SortAlgorithm::bubbleSort(BarChart& barChart)
{
	swapStatus = false;

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

			++currentRectangle;
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

void SortAlgorithm::selectionSort(BarChart& barChart)
{
	if (sortIterator < numberOfRectangles - 1)
	{
		if (currentRectangle < sortIterator + 1)
		{
			indexOfMinimum = sortIterator;
			currentRectangle = sortIterator + 1;
		}

		if (currentRectangle < numberOfRectangles)
		{
			if (rectangleArray[currentRectangle].y > rectangleArray[indexOfMinimum].y)
			{
				indexOfMinimum = currentRectangle;
			}
			++currentRectangle;
		}
		else
		{
			if (indexOfMinimum != 1)
			{
				int tempY = rectangleArray[indexOfMinimum].y, tempH = rectangleArray[indexOfMinimum].h;
				rectangleArray[indexOfMinimum].y = rectangleArray[sortIterator].y;
				rectangleArray[indexOfMinimum].h = rectangleArray[sortIterator].h;
				rectangleArray[sortIterator].y = tempY;
				rectangleArray[sortIterator].h = tempH;
				barChart.updateSwapCount(++swapCount);
			}
			currentRectangle = 0;
			++sortIterator;
		}
	}

	if (indexOfMinimum > 0 && sortIterator == numberOfRectangles - 1)
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