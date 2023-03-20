#include "SortingState.h"

/* this is a bubble sort that does 1 step at a time.  it's done this way because we need to render after every step.
*  we also need to handle events while still doing the sort so the window doesn't become unresponsive, so doing only
*  1 step at a time allows all of the rendering and event handling to happen as needed    */
void SortingState::update(BarChart& barChart)
{
	swapCount = barChart.getSwapCount();

	if (!rectangleArray)
	{
		rectangleArray = barChart.getChart().data();
	}

	if (sortIterator < numberOfRectangles)
	{
		if (currentRectangle < numberOfRectangles - sortIterator - 1)
		{
			if (rectangleArray[currentRectangle].y < rectangleArray[currentRectangle + 1].y)
			{
				int tempY = rectangleArray[currentRectangle].y, tempH = rectangleArray[currentRectangle].h;
				rectangleArray[currentRectangle].y = rectangleArray[currentRectangle + 1].y;
				rectangleArray[currentRectangle].h = rectangleArray[currentRectangle + 1].h;
				rectangleArray[currentRectangle + 1].y = tempY;
				rectangleArray[currentRectangle + 1].h = tempH;
				swapOccurred = true;
				barChart.updateSwapCount(++swapCount);
			}
			currentRectangle++;
		}
		else
		{
			currentRectangle = 0;
			sortIterator++;
			swapOccurred = false;
		}
	}

	if (sortIterator == numberOfRectangles)
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
	renderWindow.highlightRectangle(swapOccurred ? &rectangleArray[currentRectangle] : &rectangleArray[currentRectangle - 1]);
	text.render(renderWindow.getRenderer(), "Swap Count: " + std::to_string(barChart.getSwapCount()), textColor, textDisplayRect);
	renderWindow.updateWindow();
}

void SortingState::handleEvent(SDL_Event& event) {}

void SortingState::changeState(SortManager& sortManager)
{
	if (changeStateStatus)
	{
		sortManager.setState(std::make_unique<SortedState>());
		changeStateStatus = false;
	}
}