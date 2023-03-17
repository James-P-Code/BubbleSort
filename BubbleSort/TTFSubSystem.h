#pragma once

#include "SDL_ttf.h"

/*  My thinking in making this simple class comes from:
*   https://stackoverflow.com/questions/53114141/order-of-precedence-smart-pointer-and-class-destructor
*   https://stackoverflow.com/questions/6568486/when-do-we-need-a-private-constructor-in-c
* 
*   To ensure the proper freeing of Text class resources we need to free any surfaces, textures, and fonts 
*   of the Text class.  In addition to that we also need to quit the TTF subsytem by using the TTF_Quit()
*   method.  The order in which this happens matters, as there will be an error if we try to free the font
*   after TTF_Quit() has been called.  This class will ensure everything happens automatically and in the
*   correct order.     */

class TTFSubSystem
{
protected:
	TTFSubSystem();
	~TTFSubSystem();
};