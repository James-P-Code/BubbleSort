#pragma once

#include "BarChartState.h"

class UnsortedState final : public BarChartState
{
public:
	UnsortedState() {};
	UnsortedState(const bool); // Used with "true" to reset the bar chart

private:

	void update(BarChart& barChart) override;
	void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) override;
	void handleEvent(SDL_Event& event) override;
	void changeState(SortManager& sortManager) override;

	bool renderComplete = false, resetBarChart = false;
};