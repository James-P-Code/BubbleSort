#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include <memory>
#include "Constants.h"
#include "SDLSubSystem.h"
#include "Text.h"

class RenderWindow final : public SDLSubSystem
{
public:
	RenderWindow();
	void renderArray(const SDL_Rect* rectangleArray, const std::string& swapCount);
	void highlightRectangle(const SDL_Rect* rectangleArray, const int rectangleToHighlight, const std::string& swapCount);
	void sortedFlourish(const SDL_Rect* rectangleArray) const;

private:
	struct InvokeDestroy
	{
		void operator()(SDL_Window* p) const { SDL_DestroyWindow(p); }
		void operator()(SDL_Renderer* p) const { SDL_DestroyRenderer(p); }
	};
	std::unique_ptr<SDL_Window, InvokeDestroy> window;
	std::unique_ptr<SDL_Renderer, InvokeDestroy> renderer;
	Text textToRender;

	void clearRenderer() const;
};