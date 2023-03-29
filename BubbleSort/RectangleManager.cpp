#include "RectangleManager.h"

void RectangleManager::createRectangles()
{
    float xPosition = 0.f;
    int vertexIndex = 0;
    SDL_Color vertexColor = { 29, 76, 245, 255 };
    std::array<std::pair<float, SDL_Color>, numberOfRectangles> heightAndColor;
    std::mt19937 randomSeed(std::random_device{}());

    /*  We will be sorting the rectangles of the bar chart according to their height.  We want the order of the bars to
    *   be random at first (heights in random order).  To facilitate this we will first fill an array with a normalized
    *   height value for each rectangle.  Then we will shuffle that array so the heights are in a random order.  We will
    *   then create the rectangles using this random ordering of height values.  */
    for (int i = 0; i < numberOfRectangles; ++i)
    {
        heightAndColor.at(i).first = normalizeHeight(i);
        heightAndColor.at(i).second = vertexColor;

        --vertexColor.b;
        if (i % 2)
            --vertexColor.g;
    }

    std::shuffle(std::begin(heightAndColor), std::end(heightAndColor), randomSeed);

    for (size_t i = 0; i < numberOfRectangles; ++i)
    {
        Rectangle rectangle(xPosition, heightAndColor.at(i).first, rectangleWidth, heightAndColor.at(i).first + windowHeight, heightAndColor.at(i).second);

        rectangles.at(i) = rectangle;

        rectangleVertices.at(i * verticesPerRectangle) = rectangle.topLeftVertex;
        rectangleVertices.at(i * verticesPerRectangle + topRightVertexIndexOffset) = rectangle.topRightVertex;
        rectangleVertices.at(i * verticesPerRectangle + bottomRightVertexIndexOffset) = rectangle.bottomRightVertex;
        rectangleVertices.at(i * verticesPerRectangle + bottomLeftVertexIndexOffset) = rectangle.bottomLeftVertex;
        xPosition += rectangleWidth;
    }

    /*
    for (size_t i = 0; i <= totalVertices - verticesPerRectangle; i += verticesPerRectangle)
    {
        rectangleVertices.at(i) = SDL_Vertex{ { xPosition, heightAndColor.at(i / verticesPerRectangle).first }, heightAndColor.at(i / verticesPerRectangle).second }; // top left vertex
        rectangleVertices.at(i + topRightVertexIndexOffset) = SDL_Vertex{ { xPosition + rectangleWidth, heightAndColor.at(i / verticesPerRectangle).first }, heightAndColor.at(i / verticesPerRectangle).second }; // top right vertex
        rectangleVertices.at(i + bottomRightVertexIndexOffset) = SDL_Vertex{ { xPosition + rectangleWidth, heightAndColor.at(i / verticesPerRectangle).first + windowHeight }, heightAndColor.at(i / verticesPerRectangle).second }; // bottom right vertex
        rectangleVertices.at(i + bottomLeftVertexIndexOffset) = SDL_Vertex{ { xPosition, heightAndColor.at(i / verticesPerRectangle).first + windowHeight }, heightAndColor.at(i / verticesPerRectangle).second }; // bottom left vertex

        xPosition += rectangleWidth;
    }
    */

    /* To render the rectangles we will use SDL_RenderGeometry.  The thing to note about SDL_RenderGeometry is that it only
    *  renders triangles.  So each rectangle will be rendered using 2 triangles.  We can make 2 triangles from 4 vertices by
    *  rendering the vertices in a certain order.  This order is part of the SDL_RenderGeometry function, specifically the
    *  indices that can be provided.  So we can imagine a rectangle with the following vertices and their indices:
    *  Index 0 = top left corner, Index 1 = top right, Index 2 = bottom right, & Index 3 = bottom left.  If we draw the first
    *  triangle using indices 0, 1, and 2 we can then draw the second triangle using indices 2, 3 and 0 and we will get a
    *  rectangle   */
    for (size_t currentIndex = 0; currentIndex < totalIndices;)
    {
        vertexIndices.at(currentIndex++) = vertexIndex; // post-increment, so for the very first iteration this is index 0...
        vertexIndices.at(currentIndex++) = vertexIndex + topRightVertexIndexOffset; //...and then it will be index 1 when it gets here
        vertexIndices.at(currentIndex++) = vertexIndex + bottomRightVertexIndexOffset;
        vertexIndices.at(currentIndex++) = vertexIndex + bottomRightVertexIndexOffset;
        vertexIndices.at(currentIndex++) = vertexIndex + bottomLeftVertexIndexOffset;
        vertexIndices.at(currentIndex++) = vertexIndex;

        vertexIndex += verticesPerRectangle;
    }
}

const std::array<SDL_Vertex, totalVertices>& RectangleManager::getRectangleVertices() const
{
    return rectangleVertices;
}

const std::array<int, totalIndices>& RectangleManager::getIndices() const
{
    return vertexIndices;
}

const float RectangleManager::normalizeHeight(const int numberToNormalize) const
{
    constexpr float minRange = 0.0f;
    constexpr float maxRange = numberOfRectangles;
    constexpr float minBarHeight = 10.0f;
    constexpr float maxBarHeight = windowHeight;

    return (numberToNormalize - minRange) / (maxRange - minRange) * (maxBarHeight - minBarHeight) + minBarHeight;
}

void RectangleManager::swapTest()
{
    const size_t nextRectangleTopLeftVertex = 4, nextRectangleTopRightVertex = 5;

    if (currentVertex + nextRectangleTopRightVertex < totalVertices)
    {
        SDL_Color swapColor = rectangleVertices.at(currentVertex).color;
        std::swap(rectangleVertices.at(currentVertex).position.y, rectangleVertices.at(currentVertex + nextRectangleTopLeftVertex).position.y); //swap top left corner vertices
        std::swap(rectangleVertices.at(currentVertex + topRightVertexIndexOffset).position.y, rectangleVertices.at(currentVertex + nextRectangleTopRightVertex).position.y); // swap top right corner vertices

        for (size_t currentColorIndex = currentVertex; currentColorIndex < currentVertex + verticesPerRectangle; ++currentColorIndex)
        {
            std::swap(rectangleVertices.at(currentColorIndex).color, rectangleVertices.at(currentColorIndex + verticesPerRectangle).color);
        }
    }

    currentVertex += verticesPerRectangle;

    if (currentVertex >= numberOfRectangles * verticesPerRectangle)
        currentVertex = 0;
}