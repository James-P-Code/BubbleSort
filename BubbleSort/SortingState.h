#pragma once

#include "BarChartState.h"
#include "SortAlgorithm.h"

class SortingState final : public BarChartState
{
private:
	int sortIterator = 0, currentRectangle = 0, swapCount = 0, indexOfMinimum = 0;
	bool swapOccurred = false;
	SDL_Rect* rectangleArray = nullptr;
	SortAlgorithm sortAlgorithm;
	SortAlgorithm::SortType sortType;

	void update(BarChart& barChart) override;
	void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) override;
	void handleEvent(SDL_Event& event) override;
	void changeState(SortManager& sortManager) override;
};