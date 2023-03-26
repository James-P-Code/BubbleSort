#include "CocktailShakerSort.h"

CocktailShakerSort::CocktailShakerSort()
{
	this->sortName = "Cocktail Shaker Sort";
}

void CocktailShakerSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		setArray(barChart.getChart().data());

		++sortIterator;
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
		highlightRectangle = sortIterator;
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
		highlightRectangle = sortIterator;
	}

	if (sortIterator == minIndexToSort && !ascendingSort)
	{
		++sortIterator;
		++minIndexToSort;
		ascendingSort = true;
	}


}