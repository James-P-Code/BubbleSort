#pragma once

#include "BarChartState.h"
#include <array>

class UnsortedState final : public BarChartState
{
public:
	UnsortedState() {};
	UnsortedState(const bool); // Used with "true" to reset the bar chart
	virtual ~UnsortedState() {};

private:

	void update(BarChart& barChart) override;
	void render(RenderWindow& renderWindow, BarChart& barChart, Text& text) override;
	void handleEvent(SDL_Event& event) override;
	void changeState(ProgramManager& programManager) override;

	SortAlgorithm::SortType sortType = SortAlgorithm::SortType::None;
	bool renderComplete = false, resetBarChart = false;
	const std::array <std::string, 7> sortDisplayNames // REALLY NOT A FAN OF DOING IT THIS WAY
	{
		"Bubble Sort",
		"Selection Sort",
		"Insertion Sort",
		"Quick Sort",
		"Merge Sort",
		"Cocktail Shaker Sort",
		"Radix Sort"
	};
};