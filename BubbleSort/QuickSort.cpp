#include "QuickSort.h"

QuickSort::QuickSort()
{
	sortName = "Quick Sort";
	qsStack.push(std::make_pair(startIndex, endIndex));
}

void QuickSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		rectangleArray = barChart.getChart().data();
	}

	if (!qsStack.empty() || !newIteration)
	{
		if (newIteration)
		{
			startIndex = qsStack.top().first;
			endIndex = qsStack.top().second;
			qsStack.pop();

			pivotRectY = rectangleArray[endIndex].y;
			sortIterator = startIndex;
			pIndex = startIndex;

			newIteration = false;
		}

		setRectanglesToHighlight(startIndex, redHighlightColor);
		setRectanglesToHighlight(endIndex, redHighlightColor);
		if (sortIterator < endIndex)
		{
			if (rectangleArray[sortIterator].y >= pivotRectY)
			{
				swapRectangles(sortIterator, pIndex);
				barChart.updateSwapCount(swapCount);
				++pIndex;
				setRectanglesToHighlight(sortIterator, greenHighlightColor);
			}
			++sortIterator;
		}
		else
		{
			swapRectangles(pIndex, endIndex);
			barChart.updateSwapCount(swapCount);

			if (pIndex - 1 > startIndex)
			{
				qsStack.push(std::make_pair(startIndex, pIndex - 1));
			}

			if (pIndex + 1 < endIndex)
			{
				qsStack.push(std::make_pair(pIndex + 1, endIndex));
			}

			newIteration = true;
		}
	}

	if (sortIterator == endIndex && (qsStack.empty() && newIteration))
	{
		sortStatus = true;
	}
}