#include "SortedState.h"
#include "../ProgramManager/ProgramManager.h"

void SortedState::update(BarChart& barChart) {}

void SortedState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text)
{
	if (currentRectangle == 0)  // inital render
	{
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

	if (currentRectangle == numberOfRectangles)
	{
		SDL_Rect continuePromptLocation = { 10, 50, 0, 0 };
		text.render(renderWindow.getRenderer(), "Press any key to continue...", highlightColor, continuePromptLocation);
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