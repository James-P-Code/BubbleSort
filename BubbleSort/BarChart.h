#pragma once

#include "SDL.h"
#include <random>
#include <algorithm>
#include <memory>
#include <array>
#include "Constants.h"

class BarChart final
{
public:
	BarChart();
	std::array<SDL_Rect, numberOfRectangles>& getChart();
	const int getSwapCount() const;
	void updateSwapCount(int swapCount);

private:
	int swapCount;
	std::array<SDL_Rect, numberOfRectangles> rectangleArray;

	const int normalizeHeight(const int numberToNormalize) const;
};