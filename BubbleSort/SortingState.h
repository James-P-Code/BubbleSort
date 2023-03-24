#pragma once

#include "BarChartState.h"

class SortingState final : public BarChartState
{
public:
	SortingState() = delete;
	SortingState(SortAlgorithm::SortType& sortType);

private:
	SDL_Rect textDisplayRect = { 10, 10, 0, 0 };
	SDL_Color textColor = { 111, 245, 66, 255 };

	void update(BarChart& barChart) override;
	void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) override;
	void handleEvent(SDL_Event& event) override;
	void changeState(SortManager& sortManager) override;
};