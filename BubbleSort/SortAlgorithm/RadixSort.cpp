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
		if (countDigitsAtDigitPosition && sortIterator < numberOfRectangles)
		{
			digitCountArray[rectangleArray[sortIterator].y / digitPosition % base]++;
			setRectanglesToHighlight(rectangleArray[sortIterator].y % numberOfRectangles, redHighlightColor);
			++sortIterator;
		}

		if (countDigitsAtDigitPosition && sortIterator == numberOfRectangles)
		{
			countDigitsAtDigitPosition = false;
			countNumberOfDigits = true;
			sortIterator = 1;
		}

		// Find cumulative count, so it stores the actual position of the digit in the bucket
		if (countNumberOfDigits && sortIterator < base)
		{
			digitCountArray[sortIterator] += digitCountArray[sortIterator - 1];
			++sortIterator;
		}

		if (countNumberOfDigits && sortIterator == base)
		{
			countNumberOfDigits = false;
			placeBucketInOrder = true;
			sortIterator = numberOfRectangles - 1;
		}

		if (placeBucketInOrder && sortIterator >= 0)
		{
			bucket[--digitCountArray[rectangleArray[sortIterator].y / digitPosition % base]] = rectangleArray[sortIterator];
			setRectanglesToHighlight(rectangleArray[sortIterator].y % numberOfRectangles, redHighlightColor);
			--sortIterator;
		}

		if (placeBucketInOrder && sortIterator < 0)
		{
			placeBucketInOrder = false;
			updateMainArray = true;
			sortIterator = 0;
		}

		// Order the main array by using the bucket
		if (updateMainArray && sortIterator < numberOfRectangles && maxValue / (digitPosition * base) > 0)
		{
			rectangleArray[sortIterator].y = bucket[sortIterator].y;
			rectangleArray[sortIterator].h = bucket[sortIterator].h;
			setRectanglesToHighlight(sortIterator, greenHighlightColor);
			++sortIterator;
		}
		else if (updateMainArray && sortIterator < numberOfRectangles && maxValue / (digitPosition * base) == 0)  // on the final iteration reverse the order to display in ascending order
		{
			rectangleArray[sortIterator].y = bucket[(numberOfRectangles - 1) - sortIterator].y;
			rectangleArray[sortIterator].h = bucket[(numberOfRectangles - 1) - sortIterator].h;
			setRectanglesToHighlight(sortIterator, greenHighlightColor);
			++sortIterator;
		}

		if (updateMainArray && sortIterator == numberOfRectangles)
		{
			digitPosition *= base;
			updateMainArray = false;
			countDigitsAtDigitPosition = true;
			sortIterator = 0;

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