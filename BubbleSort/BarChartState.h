#pragma once

#include "SDL.h"
#include "Constants.h"
#include "BarChart.h"
#include "Text.h"
#include "RenderWindow.h"
#include "SortAlgorithm.h"
#include <string>

class SortManager;

class BarChartState
{
public:
	virtual void update(BarChart& barChart) = 0;
	virtual void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) = 0;
	virtual void handleEvent(SDL_Event& event) = 0;
	virtual void changeState(SortManager& sortManager) = 0;
	virtual ~BarChartState() {};

protected:
	bool changeStateStatus = false;  // no need to set this to false in the indivdual states, it will reset on any state change
	SortAlgorithm::SortType sortType;
};