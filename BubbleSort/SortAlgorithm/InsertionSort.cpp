#include "InsertionSort.h"

InsertionSort::InsertionSort()
{
	sortName = "Insertion Sort";
	sortIterator = 1;
}

void InsertionSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		setArray(barChart.getChart().data());
	}

	if (sortIterator < numberOfRectangles)
	{
		if (newIteration)
		{
			keyRect = rectangleArray[sortIterator];
			currentRectangle = sortIterator - 1;
			newIteration = false;
			setRectanglesToHighlight(currentRectangle, greenHighlightColor);
		}

		setRectanglesToHighlight(sortIterator, redHighlightColor);

		if (currentRectangle >= 0 && rectangleArray[currentRectangle].y < keyRect.y)
		{
			swapRectangles(currentRectangle + 1, currentRectangle);
			setRectanglesToHighlight(currentRectangle, greenHighlightColor);
			--currentRectangle;
		}

		if (currentRectangle < 0 || rectangleArray[currentRectangle].y > keyRect.y)
		{
			newIteration = true;
			++currentRectangle;
			rectangleArray[currentRectangle].y = keyRect.y;
			rectangleArray[currentRectangle].h = keyRect.h;
			++sortIterator;
		}
	}

	if (sortIterator == numberOfRectangles)
	{
		sortedStatus = true;
	}
}