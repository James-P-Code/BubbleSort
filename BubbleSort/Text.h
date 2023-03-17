#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include <memory>
#include <string>
#include <unordered_map>
#include "TTFSubSystem.h"

class Text final : public TTFSubSystem
{
public:
	Text();
	void createAtlas(SDL_Renderer* renderer);
	void renderText(SDL_Renderer* renderer, const std::string& textToRender);

private:
	struct InvokeDestroy
	{
		void operator()(TTF_Font* p) const { TTF_CloseFont(p); }
		void operator()(SDL_Texture* p) const { SDL_DestroyTexture(p); }
		void operator()(SDL_Surface* p) const { SDL_FreeSurface(p); }
	};
	std::unique_ptr<TTF_Font, InvokeDestroy> font;
	std::unique_ptr<SDL_Texture, InvokeDestroy> atlasTexture;
	std::unordered_map<int, SDL_Rect> glyphRects;
};