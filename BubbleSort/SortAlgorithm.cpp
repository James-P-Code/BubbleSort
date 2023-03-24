#include "SortAlgorithm.h"

/*
*  All of these sort functions are designed to only do 1 step at a time.  That is, each time any
*  of the sort functions is called it will only do 1 step of the sort.  It is done this way so
*  each step is rendered and drawn to the window.  This is done because everything is contained in
*  the main "game" loop (the loop in the literal main() function that drives the whole program).
*  We have to render each step or else nothing would be seen.
*/

void SortAlgorithm::sort(SortAlgorithm::SortType& sortType, BarChart& barChart)
{
	if (!rectangleArray)
	{
		rectangleArray = barChart.getChart().data();
	}

	switch (sortType)
	{
		case SortType::BubbleSort:
			sortName = "Bubble Sort";
			bubbleSort(barChart);
			break;
		case SortType::SelectionSort:
			sortName = "Selection Sort";
			selectionSort(barChart);
			break;
		case SortType::InsertionSort:
			sortName = "Insertion Sort";
			insertionSort(barChart);
			break;
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

const std::string& SortAlgorithm::getSortName() const
{
	return sortName;
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
				/*
				int tempY = rectangleArray[currentRectangle].y, tempH = rectangleArray[currentRectangle].h;
				rectangleArray[currentRectangle].y = rectangleArray[currentRectangle + 1].y;
				rectangleArray[currentRectangle].h = rectangleArray[currentRectangle + 1].h;
				rectangleArray[currentRectangle + 1].y = tempY;
				rectangleArray[currentRectangle + 1].h = tempH;
				*/
				swapRectangles(currentRectangle, currentRectangle + 1);
				swapStatus = true;
				barChart.updateSwapCount(swapCount);
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
				swapRectangles(indexOfMinimum, sortIterator);
				/*
				int tempY = rectangleArray[indexOfMinimum].y, tempH = rectangleArray[indexOfMinimum].h;
				rectangleArray[indexOfMinimum].y = rectangleArray[sortIterator].y;
				rectangleArray[indexOfMinimum].h = rectangleArray[sortIterator].h;
				rectangleArray[sortIterator].y = tempY;
				rectangleArray[sortIterator].h = tempH;
				*/
				barChart.updateSwapCount(swapCount);
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

void SortAlgorithm::insertionSort(BarChart& barChart)
{
	if (sortIterator == 0)
	{
		sortIterator = 1;
	}

	if (sortIterator < numberOfRectangles)
	{
		if (newIteration)
		{
			keyRect = rectangleArray[sortIterator];
			keyValue = sortIterator;
			currentRectangle = sortIterator - 1;
			newIteration = false;
		}

		if (currentRectangle >= 0 && rectangleArray[currentRectangle].y < keyRect.y)
		{
			swapRectangles(currentRectangle + 1, currentRectangle);
			currentRectangle--;
			barChart.updateSwapCount(swapCount);
		}

		if (currentRectangle < 0 || rectangleArray[currentRectangle].y > keyRect.y)
		{
			newIteration = true;
			currentRectangle++;
			rectangleArray[currentRectangle].y = keyRect.y;
			rectangleArray[currentRectangle].h = keyRect.h;
			sortIterator++;
		}
	}

	if (sortIterator == numberOfRectangles)
	{
		sortStatus = true;
	}
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