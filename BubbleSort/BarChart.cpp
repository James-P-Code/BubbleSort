#include "BarChart.h"

BarChart::BarChart() : swapCount(0)
{
    int xPosition = 0;
    std::array<int, numberOfRectangles> rectangleHeights;
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
}

const int BarChart::getSwapCount() const
{
    return swapCount;
}

void BarChart::updateSwapCount(int swapCount)
{
    this->swapCount = swapCount;
}

std::array<SDL_Rect, numberOfRectangles>& BarChart::getChart()
{
    return rectangleArray;
}

const int BarChart::normalizeHeight(const int numberToNormalize) const
{
    constexpr float minRange = 0.0f;
    constexpr float maxRange = numberOfRectangles;
    constexpr float minBarHeight = 10.0f;
    constexpr float maxBarHeight = windowHeight;

    return static_cast<int>((numberToNormalize - minRange) / (maxRange - minRange) * (maxBarHeight - minBarHeight) + minBarHeight);
}

void BarChart::resetChart()
{
    std::array<int, numberOfRectangles> rectangleHeights;
    std::mt19937 randomSeed(std::random_device{}());

    for (int i = 0; i < numberOfRectangles; ++i)
    {
        rectangleHeights[i] = normalizeHeight(i);
    }

    std::shuffle(std::begin(rectangleHeights), std::end(rectangleHeights), randomSeed);

    for (int i = 0; i < numberOfRectangles; ++i)
    {
        rectangleArray[i].y = rectangleHeights[i];
        rectangleArray[i].h = windowHeight - rectangleHeights[i];
    }
}