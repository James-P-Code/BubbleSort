#include "BarChart.h"

BarChart::BarChart()
{
    int xPosition = 0;
    int rectangleHeights[numberOfRectangles];
    std::mt19937 randomSeed(std::random_device{}());

    /*  We will be sorting the rectangles of the bar chart according to their height.  We want the order of the bars to
    *   be random at first (heights in random order).  To facilitate this we will first fill an array with a normalized
    *   height value for each rectangle.  Then we will shuffle that array so the heights are in a random order.  We will
    *   then create the rectangles using this random ordering of height values.  */
    for (int i = 0; i < numberOfRectangles; ++i)
    {
        rectangleHeights[i] = normalizeHeight(i);
    }

    std::shuffle(std::begin(rectangleHeights), std::end(rectangleHeights), randomSeed);

    /*  The x and y of the following rectangles define the x and y positions of the rectangle's top left corner.  The
    *   rest of the rectangle is defined using this top left corner value and the width and height values (w and h).  Because
    *
    *   of this we will use the height values we just created as the y value, while the h value will be how far the
    *   rectangle extends down from its top left corner   */
    for (int i = 0; i < numberOfRectangles; ++i)
    {
        SDL_Rect rectangle;
        rectangle.x = xPosition;
        rectangle.y = rectangleHeights[i];
        rectangle.w = rectangleWidth;
        rectangle.h = windowHeight - rectangleHeights[i];

        rectangleArray[i] = rectangle;
        xPosition += rectangleWidth;
    }

    renderWindow.renderArray(rectangleArray);
}

void BarChart::bubbleSort()
{
    bool swapOccurred;

    for (int sortIterator = 0; sortIterator < numberOfRectangles; ++sortIterator)
    {
        swapOccurred = false;
        for (int currentRectangle = 0; currentRectangle < numberOfRectangles - sortIterator - 1; ++currentRectangle)
        {
            handleEvents();  // so the window doesn't become unresponsive

            if (quitEventStatus)
            {
                return;
            }

            if (rectangleArray[currentRectangle].y < rectangleArray[currentRectangle + 1].y)
            {
                /* Here we swap rectangle values just like we would do in any other bubble sort.  Instead of swapping
                *  whole rectangles we can just swap the y and h values   */
                int tempY = rectangleArray[currentRectangle].y, tempH = rectangleArray[currentRectangle].h;
                rectangleArray[currentRectangle].y = rectangleArray[currentRectangle + 1].y;
                rectangleArray[currentRectangle].h = rectangleArray[currentRectangle + 1].h;
                rectangleArray[currentRectangle + 1].y = tempY;
                rectangleArray[currentRectangle + 1].h = tempH;
                swapOccurred = true;
            }
            renderWindow.highlightRectangle(rectangleArray, swapOccurred ? currentRectangle + 1 : currentRectangle);
        }
        if (!swapOccurred)
        {
            break;
        }
    }

    sortedStatus = true;
    renderWindow.sortedFlourish(rectangleArray);
}

const bool BarChart::isSorted() const
{
    return sortedStatus;
}

const bool BarChart::quitEvent() const
{
    return quitEventStatus;
}

const int BarChart::normalizeHeight(const int numberToNormalize) const
{
    constexpr float minRange = 0.0f;
    constexpr float maxRange = numberOfRectangles;
    constexpr float minBarHeight = 10.0f;
    constexpr float maxBarHeight = windowHeight;

    return static_cast<int>((numberToNormalize - minRange) / (maxRange - minRange) * (maxBarHeight - minBarHeight) + minBarHeight);
}

void BarChart::handleEvents()
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            quitEventStatus = true;
        }
    }
}