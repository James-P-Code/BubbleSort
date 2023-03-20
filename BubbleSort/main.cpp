//   Author:  James Pochas
//   Date:  3/12/23
//   A visualization of a bubble sort, using SDL2.  To start the sort just press any keyboard key.

#include "SDL.h"
#include "Constants.h"
#include "SortManager.h"

int main(int argc, char* argv[])
{
	SortManager sm;
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

			sm.handleEvent(event);			
		}
		sm.update();
		sm.render();
		sm.changeState();

		frameEnd = SDL_GetTicks() - frameStart;

		if (frameEnd < frameDelay) // cap the fps to the maxFPS constant value
		{
			SDL_Delay(frameDelay - frameEnd);
		}
	}

	return 0;
}