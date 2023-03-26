#pragma once

#include "BarChartState.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "CocktailShakerSort.h"
#include <memory>

class SortingState final : public BarChartState
{
public:
	SortingState() = delete;
	SortingState(const SortAlgorithm::SortType& sortType);

private:
	SDL_Rect textDisplayRect = { 10, 10, 0, 0 };
	SDL_Color textColor = { 111, 245, 66, 255 };
	int rectangleToHighlight = 0;
	std::unique_ptr<SortAlgorithm> sortAlgorithm;

	void update(BarChart& barChart) override;
	void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) override;
	void handleEvent(SDL_Event& event) override;
	void changeState(SortManager& sortManager) override;
};