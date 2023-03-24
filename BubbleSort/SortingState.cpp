#include "SortingState.h"
#include "SortManager.h"

SortingState::SortingState(SortAlgorithm::SortType& sortType)
{
	this->sortType = sortType;
}

void SortingState::update(BarChart& barChart)
{
	sortAlgorithm.sort(sortType, barChart);

	if (sortAlgorithm.isSorted())
	{
		changeStateStatus = true;
	}
}

void SortingState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text) 
{
	if (sortAlgorithm.getCurrentRectangle() > 0 && !sortAlgorithm.swapOccurred())
	{
		rectangleToHighlight = sortAlgorithm.getCurrentRectangle() - 1;
	}
	else
	{
		rectangleToHighlight = sortAlgorithm.getCurrentRectangle();
	}

	SDL_Rect sortNameRect = { 10, 30, 0, 0 };

	renderWindow.clearRenderer();
	renderWindow.renderArray(barChart.getChart().data());
	renderWindow.highlightRectangle(barChart.getChart().at(rectangleToHighlight));
	text.render(renderWindow.getRenderer(), "Swap Count: " + std::to_string(barChart.getSwapCount()), textColor, textDisplayRect);
	text.render(renderWindow.getRenderer(), sortAlgorithm.getSortName(), textColor, sortNameRect);
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