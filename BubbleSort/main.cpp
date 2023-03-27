//   Author:  James Pochas
//   Date:  3/12/23
//   A sort visualizer

/* As the name suggests, the ProgramManager class runs the show.  Its members of RenderWindow, BarChart, and Text
*  are responsible for rendering, the bar chart that will be sorted, and text output respectively.  The ProgramManager
*  implements a state pattern (BarChartState) which represent the states the bar chart can be in.  These states are
*  Unsorted (the main menu), Sorting (when active sorting is happening) and Sorted (after the sorting has finished).
*  Within each of those states the program goes through a Handle Events -> Update -> Render -> Change State process.
*  The Handle Events process is much as the name suggests, where any events like quitting might happen.  The Update process
*  deals with updating the bar chart (for example, in the Sorting state the actual sorting happens during the update).
*  The Render process is also as the name suggests, where all the rendering is taken care of.  If it is time to change states
*  then the Change State process will handle that (like changing from the Unsorted state to the Sorting state).   */

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