#include "SortedState.h"
#include "ProgramManager.h"

void SortedState::update(BarChart& barChart) {}

void SortedState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text)
{
	if (currentRectangle == 0)  // inital render
	{
		SDL_Rect textDisplayRect = { 10, 10, 0, 0 };
		SDL_Color textColor = { 111, 245, 66, 255 };
		renderWindow.renderArray(barChart.getChart().data());
	}

	if (currentRectangle < numberOfRectangles) // gradient fill flourish effect
	{
		renderWindow.highlightRectangle(barChart.getChart().at(currentRectangle), flourishColor);
		--flourishColor.r;
		--flourishColor.g;
		++currentRectangle;
	}

	if (currentRectangle <= numberOfRectangles)
	{
		renderWindow.updateWindow();
	}
}

void SortedState::handleEvent(SDL_Event& event) 
{
	if (event.type == SDL_KEYDOWN)
	{
		changeStateStatus = true;
	}
}

void SortedState::changeState(ProgramManager& programManager) 
{
	if (changeStateStatus)
	{
		programManager.setState(std::make_unique<UnsortedState>(true));
	}
}