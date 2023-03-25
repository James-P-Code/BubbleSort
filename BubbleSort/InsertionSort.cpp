#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
	this->sortName = "Insertion Sort";
}

void InsertionSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		setArray(barChart.getChart().data());
	}

	if (sortIterator == 0)
	{
		sortIterator = 1;
	}

	if (sortIterator < numberOfRectangles)
	{
		if (newIteration)
		{
			keyRect = rectangleArray[sortIterator];
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