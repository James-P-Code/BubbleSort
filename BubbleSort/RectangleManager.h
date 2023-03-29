#pragma once

#include "SDL.h"
#include "Constants.h"
#include <array>
#include <algorithm>
#include <random>

class RectangleManager
{
public:
	void createRectangles();
	const std::array<SDL_Vertex, totalVertices>& getRectangleVertices() const;
	const std::array<int, totalIndices>& getIndices() const;
	void swapTest();

private:
	struct Rectangle
	{
		SDL_Vertex topLeftVertex, topRightVertex, bottomRightVertex, bottomLeftVertex;

		bool operator < (const Rectangle& rhs) { return this->topLeftVertex.position.y < rhs.topLeftVertex.position.y; }
		Rectangle() :
			topLeftVertex({ SDL_FPoint{ 0, 0 }, defaultColor }),
			topRightVertex({ SDL_FPoint{ 0, 0 }, defaultColor }),
			bottomRightVertex({ SDL_FPoint{ 0, 0 }, defaultColor }),
			bottomLeftVertex({ SDL_FPoint{ 0, 0 }, defaultColor })
		{}
		Rectangle(const float& x, const float& y, const int width, const int height, const SDL_Color& color) :
			topLeftVertex({ SDL_FPoint { x, y }, color }),
			topRightVertex({ SDL_FPoint { x + width, y }, color }),
			bottomRightVertex({ SDL_FPoint { x + width, y + height}, color }),
			bottomLeftVertex({ SDL_FPoint { x, y + height}, color })
		{}
	};
	static constexpr size_t topRightVertexIndexOffset = 1;
	static constexpr size_t bottomRightVertexIndexOffset = 2;
	static constexpr size_t bottomLeftVertexIndexOffset = 3;
	std::array<Rectangle, numberOfRectangles> rectangles;  // used for comparisons in the sorting algorithms
	std::array<SDL_Vertex, totalVertices> rectangleVertices; // used to render the rectangles
	std::array<int, totalIndices> vertexIndices;
	size_t currentVertex = 0;

	const float normalizeHeight(const int numberToNormalize) const;
};