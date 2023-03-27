#include "SortedState.h"
#include "../ProgramManager/ProgramManager.h"

void SortedState::update(BarChart& barChart) {}

// initally when entering this state a gradient colored flourish will display.  once the user presses any key we will start the
// reset process.  the bar chart will be reset to a random order, with a rendering of this process.  once that is completed the program
// will return to the main menu
void SortedState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text)
{
	if (currentRectangle == 0 && !startReset)  // inital render
	{
		renderWindow.renderArray(barChart.getChart().data());
	}
	else if (currentRectangle == 0 && startReset)
	{
		barChart.resetChart();
		renderWindow.clearRenderer();
		startReset = false;
		currentlyResetting = true;
	}

	// render the array 1 rectangle at a time, the color depends on whether or not we are currently resetting the bar chart
	if (currentRectangle < numberOfRectangles)
	{
		renderWindow.highlightRectangle(barChart.getChart().at(currentRectangle), currentlyResetting ? defaultColor : flourishColor);
		if (!currentlyResetting)
		{
			--flourishColor.r;
			--flourishColor.g;
		}
		++currentRectangle;
	}

	if (currentRectangle <= numberOfRectangles)
	{
		renderWindow.updateWindow();
	}

	if (currentRectangle == numberOfRectangles && !currentlyResetting)
	{
		SDL_Rect continuePromptLocation = { 10, 50, 0, 0 };
		text.render(renderWindow.getRenderer(), "Press any key to continue...", highlightColor, continuePromptLocation);
	}
	else if (currentRectangle == numberOfRectangles && currentlyResetting)
	{
		changeStateStatus = true;
	}
}

void SortedState::handleEvent(SDL_Event& event) 
{
	if (event.type == SDL_KEYDOWN)
	{
		startReset = true;
		currentRectangle = 0;
	}
}

void SortedState::changeState(ProgramManager& programManager) 
{
	if (changeStateStatus)
	{
		programManager.setState(std::make_unique<UnsortedState>());
	}
}