#include "UnsortedState.h"
#include "SortManager.h"

// Use this constructor to reset the bar chart
UnsortedState::UnsortedState(const bool resetBarChart) : resetBarChart(resetBarChart) {}

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
		switch (event.key.keysym.sym)
		{
			case SDLK_1:
				sortType = SortAlgorithm::SortType::BubbleSort;
				changeStateStatus = true;
				break;
			case SDLK_2:
				sortType = SortAlgorithm::SortType::SelectionSort;
				changeStateStatus = true;
				break;
			case SDLK_3:
				sortType = SortAlgorithm::SortType::InsertionSort;
				changeStateStatus = true;
				break;
			case SDLK_4:
				sortType = SortAlgorithm::SortType::QuickSort;
				changeStateStatus = true;
				break;
		}
	}
}

void UnsortedState::changeState(SortManager& sortManager)
{
	if (changeStateStatus)
	{
		sortManager.setState(std::make_unique<SortingState>(sortType));
	}
}