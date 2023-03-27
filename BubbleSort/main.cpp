//   Author:  James Pochas
//   Date:  3/12/23
//   A sort visualizer

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