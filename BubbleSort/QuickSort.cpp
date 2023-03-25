#include "QuickSort.h"

QuickSort::QuickSort()
{
	this->sortName = "Quick Sort";
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

			pivotRect = rectangleArray[endIndex];
			sortIterator = startIndex;
			pIndex = startIndex;

			newIteration = false;
		}

		if (sortIterator < endIndex)
		{
			if (rectangleArray[sortIterator].y >= pivotRect.y)
			{
				swapRectangles(sortIterator, pIndex);
				barChart.updateSwapCount(swapCount);
				++pIndex;
				currentRectangle = sortIterator;
			}
			++sortIterator;
		}
		else
		{
			swapRectangles(pIndex, endIndex);
			barChart.updateSwapCount(swapCount);
			currentRectangle = endIndex;

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