#include "CocktailShakerSort.h"

CocktailShakerSort::CocktailShakerSort()
{
	sortName = "Cocktail Shaker Sort";
	++sortIterator;
}

void CocktailShakerSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		setArray(barChart.getChart().data());
	}

	if (sortIterator == minIndexToSort || sortIterator == maxIndexToSort)
	{
		swapStatus = false;
	}

	if (ascendingSort && sortIterator < maxIndexToSort)
	{
		if (rectangleArray[sortIterator].y > rectangleArray[sortIterator - 1].y)
		{
			swapRectangles(sortIterator, sortIterator - 1);
			swapStatus = true;
			barChart.updateSwapCount(swapCount);
		}
		setRectanglesToHighlight(sortIterator, greenHighlightColor);
		++sortIterator;
	}

	if (sortIterator == maxIndexToSort && ascendingSort)
	{
		if (!swapStatus)
		{
			sortStatus = true;
		}

		--sortIterator;
		--maxIndexToSort;
		ascendingSort = false;
	}

	if (!ascendingSort && sortIterator > minIndexToSort)
	{
		if (rectangleArray[sortIterator].y > rectangleArray[sortIterator - 1].y)
		{
			swapRectangles(sortIterator, sortIterator - 1);
			swapStatus = true;
			barChart.updateSwapCount(swapCount);
		}
		--sortIterator;
		setRectanglesToHighlight(sortIterator, greenHighlightColor);
	}

	if (sortIterator == minIndexToSort && !ascendingSort)
	{
		++sortIterator;
		++minIndexToSort;
		ascendingSort = true;
	}

	setRectanglesToHighlight(minIndexToSort, redHighlightColor);
	setRectanglesToHighlight(maxIndexToSort - 1, redHighlightColor);
}