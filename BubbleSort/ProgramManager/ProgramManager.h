#pragma once

#include"../Constants.h"
#include "../BarChartState/UnsortedState.h"
#include "../BarChartState/SortingState.h"
#include "../BarChartState/SortedState.h"
#include "../RectangleManager.h"
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

	void rectangleManagerTest();

private:
	RenderWindow renderWindow;
	BarChart barChart;
	Text text;
	RectangleManager rectangleManager;
	std::unique_ptr<BarChartState> currentState;
};