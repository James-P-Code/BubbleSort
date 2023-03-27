#pragma once

#include "SDL.h"
#include "SDL_ttf.h"
#include <memory>
#include <unordered_map>
#include "../TTFSubSystem/TTFSubSystem.h"

class Text final : public TTFSubSystem
{
public:
	Text();
	void createAtlas(SDL_Renderer* renderer);
	void render(SDL_Renderer* renderer, const std::string& textToRender, const SDL_Color& textColor, SDL_Rect destRect);

private:
	struct InvokeDestroy final
	{
		void operator()(TTF_Font* p) const { TTF_CloseFont(p); }
		void operator()(SDL_Texture* p) const { SDL_DestroyTexture(p); }
		void operator()(SDL_Surface* p) const { SDL_FreeSurface(p); }
	};
	std::unique_ptr<TTF_Font, InvokeDestroy> font;
	std::unique_ptr<SDL_Texture, InvokeDestroy> atlasTexture;
	std::unordered_map<int, SDL_Rect> glyphRects;
};