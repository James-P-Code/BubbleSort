#include "SelectionSort.h"

SelectionSort::SelectionSort()
{
	this->sortName = "Selection Sort";
}

void SelectionSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		setArray(barChart.getChart().data());
	}

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