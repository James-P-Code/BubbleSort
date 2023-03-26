#pragma once

#include "BarChartState.h"

class MenuState final : public BarChartState
{
private:
	virtual ~MenuState() {};
	void update(BarChart& barChart) override;
	void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) override;
	void handleEvent(SDL_Event& event) override;
	void changeState(ProgramManager& programManager) override;
};