#include "SortingState.h"
#include "SortManager.h"

SortingState::SortingState(const SortAlgorithm::SortType& sortType)
{
	switch (sortType)
	{
		case SortAlgorithm::SortType::BubbleSort:
			sortAlgorithm = std::make_unique<BubbleSort>();
			break;
		case SortAlgorithm::SortType::SelectionSort:
			sortAlgorithm = std::make_unique<SelectionSort>();
			break;
		case SortAlgorithm::SortType::InsertionSort:
			sortAlgorithm = std::make_unique<InsertionSort>();
			break;
		case SortAlgorithm::SortType::QuickSort:
			sortAlgorithm = std::make_unique<QuickSort>();
			break;
		case SortAlgorithm::SortType::MergeSort:
			sortAlgorithm = std::make_unique<MergeSort>();
			break;
	}
}

void SortingState::update(BarChart& barChart)
{
	sortAlgorithm->sort(barChart);

	if (sortAlgorithm->isSorted())
	{
		changeStateStatus = true;
	}
}

void SortingState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text) 
{
	if (sortAlgorithm->getCurrentRectangle() > 0 && !sortAlgorithm->swapOccurred())
	{
		rectangleToHighlight = sortAlgorithm->getCurrentRectangle() - 1;
	}
	else
	{
		rectangleToHighlight = sortAlgorithm->getCurrentRectangle();
	}

	SDL_Rect sortNameRect = { 10, 30, 0, 0 };

	renderWindow.clearRenderer();
	renderWindow.renderArray(barChart.getChart().data());
	renderWindow.highlightRectangle(barChart.getChart().at(sortAlgorithm->getHighlightRectangle()));
	text.render(renderWindow.getRenderer(), "Swap Count: " + std::to_string(barChart.getSwapCount()), textColor, textDisplayRect);
	text.render(renderWindow.getRenderer(), sortAlgorithm->getSortName(), textColor, sortNameRect);
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