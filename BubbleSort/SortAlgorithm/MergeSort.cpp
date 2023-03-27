#include "MergeSort.h"

// TODO:  Clean this up

MergeSort::MergeSort() : SortAlgorithm("Merge Sort") {}

void MergeSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		setArray(barChart.getChart().data());

		for (int i = 0; i < numberOfRectangles; ++i)
		{
			SDL_Rect rect = { rectangleArray[i].x, rectangleArray[i].y, rectangleArray[i].w, rectangleArray[i].h };
			tempArr[i] = rect;
		}
	}

	if (m <= high - low)
	{
		if (firstI < high)
		{
			if (!currentlyMerging)
			{
				from = firstI;
				mid = firstI + m - 1;
				to = findMin(firstI + 2 * m - 1, high);
			}
			merge(from, mid, to, barChart);
		}
	}
}

int MergeSort::findMin(const int x, const int y)
{
	return (x < y) ? x : y;
}

void MergeSort::merge(int from, int mid, int to, BarChart& barChart)
{
	if (!currentlyMerging)
	{
		k = from;
		i = from;
		j = mid + 1;
		currentlyMerging = true;
	}

	if (setTemp)
	{
		if (i <= mid && j <= to)
		{
			if (rectangleArray[i].y > rectangleArray[j].y)
			{
				tempArr[k].y = rectangleArray[i].y;
				tempArr[k++].h = rectangleArray[i++].h;
			}
			else
			{
				tempArr[k].y = rectangleArray[j].y;
				tempArr[k++].h = rectangleArray[j++].h;
			}
		}
		else
		{
			setTemp = false;
		}
	}
	
	if(!setTemp)
	{
		if (i < numberOfRectangles && i <= mid)
		{
			tempArr[k].y = rectangleArray[i].y;
			tempArr[k++].h = rectangleArray[i++].h;
		}
		else
		{
			mergeStarted = true;
		}
	}

	if (mergeStarted)
	{
		if (!mergeIteratorsSet)
		{
			mergeIterator = from;
			mergeIteratorsSet = true;
		}

		setRectanglesToHighlight(from, redHighlightColor);
		setRectanglesToHighlight(to, redHighlightColor);
		if (mergeIterator <= to && mergeIterator < numberOfRectangles)
		{
			setRectanglesToHighlight(mergeIterator, greenHighlightColor);
			rectangleArray[mergeIterator].y = tempArr[mergeIterator].y;
			rectangleArray[mergeIterator].h = tempArr[mergeIterator].h;
			++mergeIterator;
			++swapCount;
		}
		else
		{
			mergeIteratorsSet = false;
			currentlyMerging = false;
			mergeStarted = false;
			setTemp = true;

			firstI += 2 * m;

			if (firstI >= high)
			{
				firstI = 0;
				m = 2 * m;
			}
		}
	}

	if (m > numberOfRectangles)
	{
		sortedStatus = true;
	}
}