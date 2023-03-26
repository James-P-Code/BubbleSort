#include "UnsortedState.h"
#include "ProgramManager.h"

// Use this constructor to reset the bar chart
UnsortedState::UnsortedState(const bool resetBarChart) : resetBarChart(resetBarChart) {}

void UnsortedState::update(BarChart& barChart) 
{
	if (resetBarChart)
	{
		barChart.resetChart();
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
		switch (event.key.keysym.sym)
		{
			case SDLK_1: sortType = SortAlgorithm::SortType::BubbleSort; break;
			case SDLK_2: sortType = SortAlgorithm::SortType::SelectionSort; break;
			case SDLK_3: sortType = SortAlgorithm::SortType::InsertionSort; break;
			case SDLK_4: sortType = SortAlgorithm::SortType::QuickSort; break;
			case SDLK_5: sortType = SortAlgorithm::SortType::MergeSort; break;
			case SDLK_6: sortType = SortAlgorithm::SortType::CocktailShakerSort; break;
			case SDLK_7: sortType = SortAlgorithm::SortType::RadixSort; break;
		}

		if (sortType != SortAlgorithm::SortType::None)
		{
			changeStateStatus = true;
		}
	}
}

void UnsortedState::changeState(ProgramManager& programManager)
{
	if (changeStateStatus)
	{
		programManager.setState(std::make_unique<SortingState>(sortType));
	}
}