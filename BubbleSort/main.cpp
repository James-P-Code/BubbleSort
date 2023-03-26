//   Author:  James Pochas
//   Date:  3/12/23
//   A sort visualizer.  Planning to add a main menu, but for now press 1 for bubble sort, 2 for selection sort, 3 for insertion sort
//   4 for quick sort, 5 for merge sort, 6 for cocktail shaker sort, 7 for radix sort

#include "SDL.h"
#include "Constants.h"
#include "ProgramManager/ProgramManager.h"

int main(int argc, char* argv[])
{
	ProgramManager programManager;
	SDL_Event event;
	uint32_t frameStart, frameEnd;
	bool quit = false;

	while (!quit)
	{
		frameStart = SDL_GetTicks();

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}

			programManager.handleEvent(event);			
		}
		programManager.update();
		programManager.render();
		programManager.changeState();

		frameEnd = SDL_GetTicks() - frameStart;
		
		if (frameEnd < frameDelay) // cap the fps to the maxFPS constant value
		{
			SDL_Delay(frameDelay - frameEnd);
		}
	}

	return 0;
}