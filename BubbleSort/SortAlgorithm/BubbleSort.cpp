#include "BubbleSort.h"

BubbleSort::BubbleSort() : SortAlgorithm("Bubble Sort") {}

void BubbleSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		setArray(barChart.getChart().data());
	}

	swapOccurred = false;

	if (sortIterator < numberOfRectangles)
	{
		if (currentRectangle < numberOfRectangles - sortIterator - 1)
		{
			if (rectangleArray[currentRectangle].y < rectangleArray[currentRectangle + 1].y)
			{
				swapRectangles(currentRectangle, currentRectangle + 1);
				swapOccurred = true;
			}

			++currentRectangle;
		}
		else
		{
			currentRectangle = 0;
			sortIterator++;
			swapOccurred = false;
		}

		setRectanglesToHighlight(currentRectangle, greenHighlightColor);
	}

	if (sortIterator == numberOfRectangles)
	{
		sortedStatus = true;
	}
}