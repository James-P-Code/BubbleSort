#pragma once

#include "SDL.h"
#include "Constants.h"
#include <string>

class SortManager;
class BarChart;
class Text;
class RenderWindow;

class BarChartState
{
public:
	virtual void update(BarChart& barChart) = 0;
	virtual void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) = 0;
	virtual void handleEvent(SDL_Event& event) = 0;
	virtual void changeState(SortManager& sortManager) = 0;
	virtual ~BarChartState() {};

protected:
	bool changeStateStatus = false;
};