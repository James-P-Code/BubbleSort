#include "UnsortedState.h"

// Use this constructor to reset the bar chart
UnsortedState::UnsortedState(const bool resetBarChart)
{
	this->resetBarChart = resetBarChart;
}

void UnsortedState::update(BarChart& barChart) 
{
	if (resetBarChart)
	{
		barChart.resetChart();
		barChart.updateSwapCount(0);
		resetBarChart = false;
	}
}

void UnsortedState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text)
{
	if (!renderComplete)
	{
		SDL_Rect textDisplayRect = { 10, 10, 0, 0 };  // where the text will be displayed on the screen
		SDL_Color textColor = { 111, 245, 66, 255 };
		renderWindow.clearRenderer();
		renderWindow.renderArray(barChart.getChart().data());
		text.render(renderWindow.getRenderer(), "Swap Count: 0", textColor, textDisplayRect);
		renderWindow.updateWindow();
		renderComplete = true;
	}
}

void UnsortedState::handleEvent(SDL_Event& event)
{
	if (event.type == SDL_KEYDOWN)
	{
		changeStateStatus = true;
	}
}

void UnsortedState::changeState(SortManager& sortManager)
{
	if (changeStateStatus)
	{
		sortManager.setState(std::make_unique<SortingState>());
	}
}