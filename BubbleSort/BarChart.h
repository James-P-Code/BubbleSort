#pragma once

#include "SDL.h"
#include <random>
#include <algorithm>
#include "Constants.h"
#include "RenderWindow.h"

class BarChart final
{
public:
	BarChart();
	void bubbleSort();
	const bool isSorted() const;
	const bool quitEvent() const;

private:
	bool sortedStatus = false, quitEventStatus = false;
	SDL_Rect rectangleArray[numberOfRectangles];
	RenderWindow renderWindow;

	const int normalizeHeight(const int numberToNormalize) const;
	void handleEvents();
};