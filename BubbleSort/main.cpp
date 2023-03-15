//   Author:  James Pochas
//   Date:  3/12/23
//   A visualization of a bubble sort, using SDL2.  To start the sort just press any keyboard key.

#include "SDL.h"
#include "Constants.h"
#include "BarChart.h"

int main(int argc, char* argv[])
{
	BarChart chartToSort;
	SDL_Event event;
	bool quit = false;

	while (!quit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
			if (event.type == SDL_KEYDOWN && !chartToSort.isSorted())
			{
				chartToSort.bubbleSort();
			}
		}
		if (chartToSort.quitEvent())
		{
			quit = true;
		}
		SDL_Delay(delayTime);
	}

	SDL_Quit();
	return 0;
}