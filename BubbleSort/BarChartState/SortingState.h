#pragma once

#include "BarChartState.h"
#include "../SortAlgorithm/BubbleSort.h"
#include "../SortAlgorithm/SelectionSort.h"
#include "../SortAlgorithm/InsertionSort.h"
#include "../SortAlgorithm/QuickSort.h"
#include "../SortAlgorithm/MergeSort.h"
#include "../SortAlgorithm/CocktailShakerSort.h"
#include "../SortAlgorithm/RadixSort.h"
#include <memory>

class SortingState final : public BarChartState
{
public:
	SortingState() = delete;
	SortingState(const SortAlgorithm::SortType& sortType);
	virtual ~SortingState() {};

private:
	SDL_Rect textDisplayRect = { 10, 10, 0, 0 };
	SDL_Color textColor = { 111, 245, 66, 255 };
	std::unique_ptr<SortAlgorithm> sortAlgorithm;

	void update(BarChart& barChart) override;
	void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) override;
	void handleEvent(SDL_Event& event) override;
	void changeState(ProgramManager& programManager) override;
};