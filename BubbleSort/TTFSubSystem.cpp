#include "TTFSubSystem.h"

TTFSubSystem::TTFSubSystem()
{
	TTF_Init();
}

TTFSubSystem::~TTFSubSystem()
{
	TTF_Quit();
}