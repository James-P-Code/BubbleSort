#include "ProgramManager.h"

ProgramManager::ProgramManager() : currentState(std::make_unique<UnsortedState>())
{
	text.createAtlas(renderWindow.getRenderer());
}

void ProgramManager::update()
{
	currentState->update(barChart);
}

void ProgramManager::render()
{
	currentState->render(renderWindow, barChart, text);
}

void ProgramManager::handleEvent(SDL_Event& event) const
{
	currentState->handleEvent(event);
}

void ProgramManager::changeState()
{
	currentState->changeState(*this);
}

void ProgramManager::setState(std::unique_ptr<BarChartState> newState)
{
	currentState = std::move(newState);
}