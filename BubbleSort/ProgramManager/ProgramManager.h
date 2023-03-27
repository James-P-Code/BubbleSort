#pragma once

#include "../BarChartState/UnsortedState.h"
#include "../BarChartState/SortingState.h"
#include "../BarChartState/SortedState.h"
#include <memory>

class ProgramManager final
{
public:
	ProgramManager();
	void update();
	void render();
	void handleEvent(SDL_Event& event) const;
	void changeState();
	void setState(std::unique_ptr<BarChartState> newState);

private:
	RenderWindow renderWindow;
	BarChart barChart;
	Text text;
	std::unique_ptr<BarChartState> currentState;
};