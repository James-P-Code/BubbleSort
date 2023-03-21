#include "MenuState.h"

void MenuState::update(BarChart& barChart) {}

void MenuState::render(RenderWindow& renderWindow, BarChart& barChart, Text& text)
{
	SDL_Rect bgTest = { 0, 0, windowWidth, windowHeight };
	SDL_Color bgTestColor = { 0, 0, 0, 200 };

	renderWindow.renderArray(barChart.getChart().data());
	renderWindow.renderTranslucentRect(bgTest, bgTestColor);
	SDL_Rect mainTextDisplayRect = { 10, 10, 0, 0 };
	SDL_Rect secondaryText = { 50, 50, 0 , 0 };
	SDL_Color textColor = { 111, 245, 66, 255 };
	text.render(renderWindow.getRenderer(), "Main Menu Test", textColor, mainTextDisplayRect);
	text.render(renderWindow.getRenderer(), "Some other text", textColor, secondaryText);
	renderWindow.updateWindow();
}

void MenuState::handleEvent(SDL_Event& event) {}

void MenuState::changeState(SortManager& sortManager) {}