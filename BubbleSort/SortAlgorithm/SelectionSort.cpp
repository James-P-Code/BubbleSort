#include "SelectionSort.h"

SelectionSort::SelectionSort() : SortAlgorithm("Selection Sort") {}

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
			setRectanglesToHighlight(currentRectangle, greenHighlightColor);
			++currentRectangle;
		}
		else
		{
			if (indexOfMinimum != 1)
			{
				swapRectangles(indexOfMinimum, sortIterator);
			}
			currentRectangle = 0;
			++sortIterator;
			setRectanglesToHighlight(currentRectangle, greenHighlightColor);
		}
	}

	if (indexOfMinimum > 0 && sortIterator == numberOfRectangles - 1)
	{
		sortedStatus = true;
	}
}