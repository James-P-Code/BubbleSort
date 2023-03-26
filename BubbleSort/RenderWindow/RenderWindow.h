#pragma once

#include "SDL.h"
#include <memory>
#include "../Constants.h"
#include "../SDLSubSystem/SDLSubSystem.h"

class RenderWindow final : public SDLSubSystem
{
public:
	RenderWindow();
	SDL_Renderer* getRenderer() const;
	void renderArray(const SDL_Rect* rectangleArray) const;
	void highlightRectangle(const SDL_Rect& rectangle, const SDL_Color& fillColor = highlightColor) const;
	void renderTranslucentRect(const SDL_Rect&, const SDL_Color&) const;
	void updateWindow() const;
	void clearRenderer() const;

private:
	struct InvokeDestroy final
	{
		void operator()(SDL_Window* p) const { SDL_DestroyWindow(p); }
		void operator()(SDL_Renderer* p) const { SDL_DestroyRenderer(p); }
	};
	std::unique_ptr<SDL_Window, InvokeDestroy> window;
	std::unique_ptr<SDL_Renderer, InvokeDestroy> renderer;
};