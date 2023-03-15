#include "RenderWindow.h"

RenderWindow::RenderWindow()
{
    constexpr int driverIndex = -1;

    SDL_InitSubSystem(SDL_INIT_VIDEO);
    window = std::unique_ptr<SDL_Window, InvokeDestroy>(SDL_CreateWindow("Bubblesort Visualization", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, SDL_WINDOW_SHOWN));
    renderer = std::unique_ptr<SDL_Renderer, InvokeDestroy>(SDL_CreateRenderer(window.get(), driverIndex, SDL_RENDERER_PRESENTVSYNC));
}

void RenderWindow::renderArray(const SDL_Rect* rectangleArray) const
{
    clearRenderer();
    SDL_SetRenderDrawColor(renderer.get(), defaultColor.r, defaultColor.g, defaultColor.b, defaultColor.a);
    SDL_RenderFillRects(renderer.get(), rectangleArray, numberOfRectangles);
    SDL_RenderPresent(renderer.get());
}

void RenderWindow::highlightRectangle(const SDL_Rect* rectangleArray, const int rectangleToHighlight) const
{
    clearRenderer();
    // render and fill all of the rectangles and then...
    SDL_SetRenderDrawColor(renderer.get(), defaultColor.r, defaultColor.g, defaultColor.b, defaultColor.a);
    SDL_RenderFillRects(renderer.get(), rectangleArray, numberOfRectangles);
    // ...render and fill the rectangle we want to highlight
    SDL_SetRenderDrawColor(renderer.get(), highlightColor.r, highlightColor.g, highlightColor.b, highlightColor.a);
    SDL_RenderFillRect(renderer.get(), &rectangleArray[rectangleToHighlight]);

    SDL_RenderPresent(renderer.get());
}

void RenderWindow::sortedFlourish(const SDL_Rect* rectangleArray) const
{
    SDL_Color flourishColor = { 143, 245, 42, 255 };  // RGBA color values

    SDL_SetRenderDrawColor(renderer.get(), defaultColor.r, defaultColor.g, defaultColor.b, defaultColor.a);
    SDL_RenderFillRects(renderer.get(), rectangleArray, numberOfRectangles);

    for (int i = 0; i < numberOfRectangles; ++i)
    {
        SDL_SetRenderDrawColor(renderer.get(), flourishColor.r, flourishColor.g, flourishColor.b, flourishColor.a);
        SDL_RenderFillRect(renderer.get(), &rectangleArray[i]);
        SDL_RenderPresent(renderer.get());
        // to achieve a gradient effect we decrement the red and green values
        --flourishColor.r;
        --flourishColor.g;
    }
}

void RenderWindow::clearRenderer() const
{
    SDL_SetRenderDrawColor(renderer.get(), backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
    SDL_RenderClear(renderer.get());
}