#include "QuickSort.h"

QuickSort::QuickSort() : SortAlgorithm("Quick Sort")
{
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
			pivotIndex = startIndex;

			newIteration = false;
		}

		setRectanglesToHighlight(pivotIndex, greenHighlightColor);
		setRectanglesToHighlight(sortIterator, greenHighlightColor);
		setRectanglesToHighlight(startIndex, redHighlightColor);
		setRectanglesToHighlight(endIndex, redHighlightColor);
		if (sortIterator < endIndex)
		{
			if (rectangleArray[sortIterator].y >= pivotRectY)
			{
				swapRectangles(sortIterator, pivotIndex);
				++pivotIndex;
				setRectanglesToHighlight(sortIterator, greenHighlightColor);
			}
			++sortIterator;
		}
		else
		{
			swapRectangles(pivotIndex, endIndex);
			setRectanglesToHighlight(pivotIndex, greenHighlightColor);

			if (pivotIndex - 1 > startIndex)
			{
				qsStack.push(std::make_pair(startIndex, pivotIndex - 1));
			}

			if (pivotIndex + 1 < endIndex)
			{
				qsStack.push(std::make_pair(pivotIndex + 1, endIndex));
			}

			newIteration = true;
		}
	}

	if (sortIterator == endIndex && (qsStack.empty() && newIteration))
	{
		sortedStatus = true;
	}
}