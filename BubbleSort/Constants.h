#pragma once

#include "SDL.h"

constexpr int windowWidth = 800;
constexpr int windowHeight = 600;
constexpr int maxFPS = 144;
constexpr int frameDelay = 1000 / maxFPS;

constexpr int rectangleWidth = 8;
constexpr int numberOfRectangles = windowWidth / rectangleWidth;
constexpr int indicesPerRectangle = 6;
constexpr int verticesPerRectangle = 4;
constexpr size_t totalVertices = numberOfRectangles * verticesPerRectangle;
constexpr size_t totalIndices = numberOfRectangles * indicesPerRectangle;

// RGBA color values
constexpr SDL_Color backgroundColor = { 0, 0, 0, 255 };
constexpr SDL_Color defaultColor = { 255, 255, 255, 255 };
constexpr SDL_Color highlightColor = { 66, 245, 72, 255 };