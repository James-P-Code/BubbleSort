#include "SortingState.h"
#include "ProgramManager.h"

SortingState::SortingState(const SortAlgorithm::SortType& sortType)
{
	switch (sortType)
	{
		case SortAlgorithm::SortType::BubbleSort: sortAlgorithm = std::make_unique<BubbleSort>(); break;
		case SortAlgorithm::SortType::SelectionSort: sortAlgorithm = std::make_unique<SelectionSort>(); break;
		case SortAlgorithm::SortType::InsertionSort: sortAlgorithm = std::make_unique<InsertionSort>(); break;
		case SortAlgorithm::SortType::QuickSort: sortAlgorithm = std::make_unique<QuickSort>(); break;
		case SortAlgorithm::SortType::MergeSort: sortAlgorithm = std::make_unique<MergeSort>(); break;
		case SortAlgorithm::SortType::CocktailShakerSort: sortAlgorithm = std::make_unique<CocktailShakerSort>(); break;
		case SortAlgorithm::SortType::RadixSort: sortAlgorithm = std::make_unique<RadixSort>(); break;
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
	SDL_Rect sortNameRect = { 10, 30, 0, 0 };

	renderWindow.clearRenderer();
	renderWindow.renderArray(barChart.getChart().data());
	for (const auto& rectangle : sortAlgorithm->getRectanglesToHighlight())
	{
		renderWindow.highlightRectangle(barChart.getChart().at(rectangle.first), rectangle.second);
	}
	sortAlgorithm->clearRectanglesToHighlight();
	text.render(renderWindow.getRenderer(), "Swap Count: " + std::to_string(sortAlgorithm->getSwapCount()), textColor, textDisplayRect);
	text.render(renderWindow.getRenderer(), sortAlgorithm->getSortName(), textColor, sortNameRect);
	renderWindow.updateWindow();
}

void SortingState::handleEvent(SDL_Event& event) {}

void SortingState::changeState(ProgramManager& programManager)
{
	if (changeStateStatus)
	{
		programManager.setState(std::make_unique<SortedState>());
	}
}