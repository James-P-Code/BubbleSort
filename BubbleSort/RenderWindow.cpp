#include "RenderWindow.h"

RenderWindow::RenderWindow()
{
    constexpr int driverIndex = -1;

    window = std::unique_ptr<SDL_Window, InvokeDestroy>(SDL_CreateWindow("Bubblesort Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN));
    renderer = std::unique_ptr<SDL_Renderer, InvokeDestroy>(SDL_CreateRenderer(window.get(), driverIndex, SDL_RENDERER_PRESENTVSYNC));
}

SDL_Renderer* RenderWindow::getRenderer() const
{
    return renderer.get();
}

void RenderWindow::renderArray(const SDL_Rect* rectangleArray) const
{
    SDL_SetRenderDrawColor(renderer.get(), defaultColor.r, defaultColor.g, defaultColor.b, defaultColor.a);
    SDL_RenderFillRects(renderer.get(), rectangleArray, numberOfRectangles);
}

void RenderWindow::highlightRectangle(const SDL_Rect* rectangle, const SDL_Color& fillColor) const
{
    SDL_SetRenderDrawColor(renderer.get(), fillColor.r, fillColor.g, fillColor.b, fillColor.a);
    SDL_RenderFillRect(renderer.get(), rectangle);
}

void RenderWindow::updateWindow() const
{
    SDL_RenderPresent(renderer.get());
}

void RenderWindow::clearRenderer() const
{
    SDL_SetRenderDrawColor(renderer.get(), backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderClear(renderer.get());
}