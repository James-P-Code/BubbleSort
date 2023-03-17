#include "SDLSubSystem.h"

SDLSubSystem::SDLSubSystem()
{
	SDL_InitSubSystem(SDL_INIT_VIDEO);
}

SDLSubSystem::~SDLSubSystem()
{
	SDL_Quit();
}