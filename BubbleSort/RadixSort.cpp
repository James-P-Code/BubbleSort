#include "RadixSort.h"

RadixSort::RadixSort()
{
	sortName = "Radix Sort";
}

void RadixSort::sort(BarChart& barChart)
{
	if (!rectangleArray)
	{
		setArray(barChart.getChart().data());

		for (int i = 0; i < numberOfRectangles; ++i)
		{
			if (rectangleArray[i].y > maxValue)
			{
				maxValue = rectangleArray[i].y;
			}
		}
	}

	if (maxValue / digitPosition > 0)
	{
		// Count number of times each digit occurred at digitPosition in every array element
		if (countDigitsAtDigitPosition && countIterator < numberOfRectangles)
		{
			digitCountArray[rectangleArray[countIterator].y / digitPosition % base]++;
			setRectanglesToHighlight(rectangleArray[countIterator].y % numberOfRectangles, redHighlightColor);
			++countIterator;
		}

		if (countDigitsAtDigitPosition && countIterator == numberOfRectangles)
		{
			countDigitsAtDigitPosition = false;
			countNumberOfDigits = true;
			countIterator = 1;
		}

		// Find cumulative count, so it stores the actual position of the digit in the bucket
		if (countNumberOfDigits && countIterator < base)
		{
			digitCountArray[countIterator] += digitCountArray[countIterator - 1];
			++countIterator;
		}

		if (countNumberOfDigits && countIterator == base)
		{
			countNumberOfDigits = false;
			keepOrder = true;
			countIterator = numberOfRectangles - 1;
		}

		if (keepOrder && countIterator >= 0)
		{
			bucket[--digitCountArray[rectangleArray[countIterator].y / digitPosition % base]] = rectangleArray[countIterator];		
			--countIterator;
		}

		if (keepOrder && countIterator < 0)
		{
			keepOrder = false;
			updateMainArray = true;
			countIterator = 0;
		}

		// Order the main array by using the bucket
		if (updateMainArray && countIterator < numberOfRectangles)
		{
			rectangleArray[countIterator].y = bucket[countIterator].y;
			rectangleArray[countIterator].h = bucket[countIterator].h;
			setRectanglesToHighlight(countIterator, greenHighlightColor);
			++countIterator;
		}

		if (updateMainArray && countIterator == numberOfRectangles)
		{
			digitPosition *= base;
			updateMainArray = false;
			countDigitsAtDigitPosition = true;
			countIterator = 0;

			for (int i = 0; i < base; ++i)
			{
				digitCountArray[i] = 0;
			}
		}

		if (maxValue / digitPosition == 0)
		{
			sortedStatus = true;
		}
	}
}