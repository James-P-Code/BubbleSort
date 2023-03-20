#pragma once

#include "SDL.h"
#include "Constants.h"
#include "BarChart.h"

class BarChart;

class SortAlgorithm
{
public:
	virtual void performSort(BarChart& barChart, SDL_Renderer* renderer) = 0;
};