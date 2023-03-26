#pragma once

#include "UnsortedState.h"
#include "SortingState.h"
#include "SortedState.h"
#include <memory>

class UnsortedState;
class SortingState;
class SortedState;

class ProgramManager final
{
public:
	ProgramManager();
	void update();
	void render();
	void handleEvent(SDL_Event& event);
	void changeState();
	void setState(std::unique_ptr<BarChartState> newState);

private:
	RenderWindow renderWindow;
	BarChart barChart;
	Text text;
	std::unique_ptr<BarChartState> currentState;
};