#include "SortManager.h"

SortManager::SortManager() : currentState(std::make_unique<UnsortedState>())
{
	text.createAtlas(renderWindow.getRenderer());
}

void SortManager::update()
{
	currentState->update(barChart);
}

void SortManager::render()
{
	currentState->render(renderWindow, barChart, text);
}

void SortManager::handleEvent(SDL_Event& event)
{
	currentState->handleEvent(event);
}

void SortManager::changeState()
{
	currentState->changeState(*this);
}

void SortManager::setState(std::unique_ptr<BarChartState> newState)
{
	currentState = std::move(newState);
}