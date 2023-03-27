#include "UnsortedState.h"
#include "../ProgramManager/ProgramManager.h"

void UnsortedState::update(BarChart& barChart) {}

void UnsortedState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text)
{
	if (!renderComplete)
	{
		int menuOptionNumber = 1;
		SDL_Rect translucentBackground = { 0, 0, windowWidth, windowHeight };
		SDL_Color translucentColor = { 0, 0, 0, 220 };
		SDL_Rect sortDisplayNameLocation = { 275, 200, 0, 0 };

		renderWindow.renderArray(barChart.getChart().data());
		renderWindow.renderTranslucentRect(translucentBackground, translucentColor);

		for (const std::string& displayName : sortDisplayNames)
		{
			text.render(renderWindow.getRenderer(), std::to_string(menuOptionNumber) + " " + displayName, highlightColor, sortDisplayNameLocation);
			++menuOptionNumber;
			sortDisplayNameLocation.y += 30;
		}

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