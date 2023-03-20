#include "SortedState.h"

void SortedState::update(BarChart& barChart) {}

void SortedState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text)
{
	if (currentRectangle == 0)  // inital render
	{
		SDL_Rect textDisplayRect = { 10, 10, 0, 0 };
		SDL_Color textColor = { 111, 245, 66, 255 };
		renderWindow.renderArray(barChart.getChart().data());
		text.render(renderWindow.getRenderer(), "Swap Count: " + std::to_string(barChart.getSwapCount()), textColor, textDisplayRect);
	}

	if (currentRectangle < numberOfRectangles) // gradient fill flourish effect
	{
		renderWindow.highlightRectangle(&barChart.getChart().at(currentRectangle), flourishColor);
		--flourishColor.r;
		--flourishColor.g;
		++currentRectangle;
	}

	if (currentRectangle <= numberOfRectangles)
	{
		renderWindow.updateWindow();
	}
}

void SortedState::handleEvent(SDL_Event& event) {}

void SortedState::changeState(SortManager& sortManager) {}