#pragma once

#include "BarChartState.h"
#include "SortManager.h"
#include "BarChart.h"
#include "Text.h"
#include "RenderWindow.h"

class SortingState final : public BarChartState
{
private:
	int sortIterator = 0, currentRectangle = 0, swapCount = 0;
	bool swapOccurred = false;
	SDL_Rect* rectangleArray = nullptr;

	void update(BarChart& barChart) override;
	void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) override;
	void handleEvent(SDL_Event& event) override;
	void changeState(SortManager& sortManager) override;
};