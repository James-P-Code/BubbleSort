#include "Text.h"

Text::Text()
{
	font = std::unique_ptr<TTF_Font, InvokeDestroy>(TTF_OpenFont("PressStart2P-Regular.ttf", 16));
}

/*  the createAtlas function will create one single texture we can then use to render any future text.  because this program intends to have text
*   displays that change often (the swap counter, for instance) it is more efficient to create this glyph atlas texture and render from that.
*   otherwise we would have to create a surface and texture for every single text update, and often that texture would only be needed for a few
*   frames at most.  instead of doing those expensive operations many times, we'll use this much more efficient method.   */
void Text::createAtlas(SDL_Renderer* renderer)
{
	constexpr int nullTerminatedChar = 2, textureSize = 512, depth = 32, alphaMask = 0xff;
	constexpr SDL_Color white = { 255, 255, 255, 255 }, black = { 0, 0, 0 ,0 };
	int i;
	SDL_Rect destRect = { 0, 0, 0, 0 };
	SDL_Surface* s = SDL_CreateRGBSurface(0, textureSize, textureSize, depth, black.r, black.g, black.b, alphaMask);
	std::unique_ptr<SDL_Surface, InvokeDestroy> surface;
	std::unique_ptr<SDL_Surface, InvokeDestroy> text;
	surface.reset(s);  // make the unique_ptr the owner of the pointer

	SDL_SetColorKey(surface.get(), SDL_TRUE, SDL_MapRGBA(surface->format, black.r, black.g, black.b, black.a));  // set the background of the text surface to be transparent

	for (i = ' '; i < 'z'; ++i)
	{
		/* some of the functions we will be using require a const char* parameter, which specifically has to be null terminated.
		*  to faciliate this we can use this small array, and creating it like this makes it so it is implicitly null terminated.  */
		char cc[nullTerminatedChar] = { static_cast<char>(i) };
		text = std::unique_ptr<SDL_Surface, InvokeDestroy>(TTF_RenderUTF8_Blended(font.get(), cc, white));

		// get the size of the character we just rendered and set destRect's width and height accordingly
		TTF_SizeText(font.get(), cc, &destRect.w, &destRect.h);

		if (destRect.x + destRect.y >= textureSize)
		{
			destRect.x = 0;
			destRect.y += destRect.h + 1;
		}
		
		SDL_BlitSurface(text.get(), nullptr, surface.get(), &destRect);  // copy the text surface onto the surface we will use for the full texture

		glyphRects[i] = { destRect.x, destRect.y, destRect.w, destRect.h };
		destRect.x += destRect.w;
	}
	atlasTexture = std::unique_ptr<SDL_Texture, InvokeDestroy>(SDL_CreateTextureFromSurface(renderer, surface.get())); // create the full atlas texture
}

void Text::renderText(SDL_Renderer* renderer, const std::string& textToRender)
{
	constexpr SDL_Color defaultFontColor = { 111, 245, 66 };
	SDL_Rect destRect;
	SDL_SetTextureColorMod(atlasTexture.get(), defaultFontColor.r, defaultFontColor.g, defaultFontColor.b);

	// x and y position where the text will start to be displayed
	destRect.x = 10;
	destRect.y = 10;

	for (const char& c : textToRender)
	{
		destRect.w = glyphRects[static_cast<int>(c)].w;
		destRect.h = glyphRects[static_cast<int>(c)].h;
		SDL_RenderCopy(renderer, atlasTexture.get(), &glyphRects[static_cast<int>(c)], &destRect);
		destRect.x += glyphRects[static_cast<int>(c)].w;
	}
}