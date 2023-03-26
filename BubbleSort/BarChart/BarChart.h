#pragma once

#include "SDL.h"
#include "../Constants.h"
#include <random>
#include <algorithm>
#include <memory>
#include <array>

class BarChart final
{
public:
	BarChart();
	std::array<SDL_Rect, numberOfRectangles>& getChart();
	void resetChart();

private:
	std::array<SDL_Rect, numberOfRectangles> rectangleArray;

	const int normalizeHeight(const int numberToNormalize) const;
};