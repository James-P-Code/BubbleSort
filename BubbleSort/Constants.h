#pragma once

constexpr int windowWidth = 800;
constexpr int windowHeight = 600;
constexpr int rectangleWidth = 8;
constexpr int numberOfRectangles = windowWidth / rectangleWidth;
constexpr int maxFPS = 144;
constexpr int frameDelay = 1000 / maxFPS;

// RGBA color values
constexpr SDL_Color backgroundColor = { 0, 0, 0, 255 };
constexpr SDL_Color defaultColor = { 255, 255, 255, 255 };
constexpr SDL_Color highlightColor = { 66, 245, 72, 255 };