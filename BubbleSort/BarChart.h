#pragma once

#include "SDL.h"
#include "Constants.h"
#include <random>
#include <algorithm>
#include <memory>
#include <array>

class BarChart final
{
public:
	BarChart();
	std::array<SDL_Rect, numberOfRectangles>& getChart();
	const int getSwapCount() const;
	void updateSwapCount(int swapCount);
	void resetChart();

private:
	int swapCount;
	std::array<SDL_Rect, numberOfRectangles> rectangleArray;

	const int normalizeHeight(const int numberToNormalize) const;
};