#pragma once

#include "BarChartState.h"

class SortedState final : public BarChartState
{
public:
	virtual ~SortedState() {};

private:
	SDL_Color flourishColor = { 143, 245, 42, 255 };  // RGBA color values
	int currentRectangle = 0;

	void update(BarChart& barChart) override;
	void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) override;
	void handleEvent(SDL_Event& event) override;
	void changeState(ProgramManager& programManager) override;
};