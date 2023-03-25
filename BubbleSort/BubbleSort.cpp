#include "BubbleSort.h"

BubbleSort::BubbleSort()
{
	this->sortName = "Bubble Sort";
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

		highlightRectangle = currentRectangle;
	}

	if (sortIterator == numberOfRectangles)
	{
		sortStatus = true;
	}
}