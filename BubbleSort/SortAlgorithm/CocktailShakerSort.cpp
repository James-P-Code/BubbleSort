#include "CocktailShakerSort.h"

CocktailShakerSort::CocktailShakerSort() : SortAlgorithm("Cocktail Shaker Sort")
{
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
		swapOccurred = false;
	}

	if (ascendingSort && sortIterator < maxIndexToSort)
	{
		if (rectangleArray[sortIterator].y > rectangleArray[sortIterator - 1].y)
		{
			swapRectangles(sortIterator, sortIterator - 1);
			swapOccurred = true;
		}
		setRectanglesToHighlight(sortIterator, greenHighlightColor);
		++sortIterator;
	}

	if (sortIterator == maxIndexToSort && ascendingSort)
	{
		if (!swapOccurred)
		{
			sortedStatus = true;
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
			swapOccurred = true;
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