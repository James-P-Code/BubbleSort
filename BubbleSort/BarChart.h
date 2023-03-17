#pragma once

#include "SDL.h"
#include <random>
#include <algorithm>
#include <string>
#include "Constants.h"
#include "RenderWindow.h"

class BarChart final
{
public:
	BarChart();
	void bubbleSort();
	const bool isSorted() const;
	const bool quitEvent() const;
	const std::string getSwapCount() const;

private:
	bool sortedStatus = false, quitEventStatus = false;
	int swapCount = 0;
	std::string swapCountDisplay = "Swap Count: 0";
	SDL_Rect rectangleArray[numberOfRectangles];
	RenderWindow renderWindow;

	const int normalizeHeight(const int numberToNormalize) const;
	void handleEvents();
};