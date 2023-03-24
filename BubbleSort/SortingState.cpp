#include "SortingState.h"
#include "SortManager.h"

/* this is a sort that does 1 step at a time.  it's done this way because we need to render after every step.
*  we also need to handle events while still doing the sort so the window doesn't become unresponsive, so doing only
*  1 step at a time allows all of the rendering and event handling to happen as needed    */
void SortingState::update(BarChart& barChart)
{
	swapCount = barChart.getSwapCount();
	sortType = SortAlgorithm::SortType::BubbleSort;

	if (!rectangleArray)
	{
		rectangleArray = barChart.getChart().data();
	}

	if (sortType == SortAlgorithm::SortType::BubbleSort)
	{
		sortAlgorithm.bubbleSort(barChart);
	}


	/* SELECTION SORT 
	if (!rectangleArray)
	{
		rectangleArray = barChart.getChart().data();
	}
	if (sortIterator < numberOfRectangles - 1)
	{

		if (currentRectangle < sortIterator + 1)
		{
			indexOfMinimum = sortIterator;
			currentRectangle = sortIterator + 1;
		}

		if (currentRectangle < numberOfRectangles)
		{
			if (rectangleArray[currentRectangle].y > rectangleArray[indexOfMinimum].y)
			{
				indexOfMinimum = currentRectangle;
			}
			++currentRectangle;
		}
		else
		{
			if (indexOfMinimum != 1)
			{
				int tempY = rectangleArray[indexOfMinimum].y, tempH = rectangleArray[indexOfMinimum].h;
				rectangleArray[indexOfMinimum].y = rectangleArray[sortIterator].y;
				rectangleArray[indexOfMinimum].h = rectangleArray[sortIterator].h;
				rectangleArray[sortIterator].y = tempY;
				rectangleArray[sortIterator].h = tempH;
				barChart.updateSwapCount(++swapCount);
			}
			currentRectangle = 0;
			++sortIterator;
		}
	}
	*/

	/*
	if (sortIterator == numberOfRectangles || (indexOfMinimum > 0 && sortIterator == numberOfRectangles - 1))
	{
		changeStateStatus = true;
	}
	*/
	if (sortAlgorithm.isSorted())
	{
		changeStateStatus = true;
	}
}

void SortingState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text) 
{
	SDL_Rect textDisplayRect = { 10, 10, 0, 0 };
	SDL_Color textColor = { 111, 245, 66, 255 };
	renderWindow.clearRenderer();
	renderWindow.renderArray(rectangleArray);
	renderWindow.highlightRectangle(sortAlgorithm.swapOccurred() ? rectangleArray[sortAlgorithm.getCurrentRectangle()] : rectangleArray[sortAlgorithm.getCurrentRectangle() - 1]);
	text.render(renderWindow.getRenderer(), "Swap Count: " + std::to_string(barChart.getSwapCount()), textColor, textDisplayRect);
	renderWindow.updateWindow();
}

void SortingState::handleEvent(SDL_Event& event) {}

void SortingState::changeState(SortManager& sortManager)
{
	if (changeStateStatus)
	{
		sortManager.setState(std::make_unique<SortedState>());
	}
}