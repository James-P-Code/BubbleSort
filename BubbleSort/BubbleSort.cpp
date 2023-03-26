#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
	sortName = "Bubble Sort";
}

void BubbleSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		setArray(barChart.getChart().data());
	}

	swapStatus = false;

	if (sortIterator < numberOfRectangles)
	{
		if (currentRectangle < numberOfRectangles - sortIterator - 1)
		{
			if (rectangleArray[currentRectangle].y < rectangleArray[currentRectangle + 1].y)
			{
				swapRectangles(currentRectangle, currentRectangle + 1);
				swapStatus = true;
			}

			++currentRectangle;
		}
		else
		{
			currentRectangle = 0;
			sortIterator++;
			swapStatus = false;
		}

		setRectanglesToHighlight(currentRectangle, greenHighlightColor);
	}

	if (sortIterator == numberOfRectangles)
	{
		sortedStatus = true;
	}
}