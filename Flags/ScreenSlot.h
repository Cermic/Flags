#pragma once
#include <SDL.h>
#include <vector>

class ScreenSlot
{
public:
	// Initialises the vector with the given size.
	void InitialiseSlots(int numberOfSlots);
	// Renders the Slots
	void RenderSlots();
	// Choose a slot to edit and then input the rect - Could use a wrapper method I think
	void SetRect(int rectIndex, SDL_Rect rect) { slots.at(rectIndex) = rect; }
	// Get a slot from the vector using it's index
	SDL_Rect GetRect(int index) { return slots.at(index); }
private:
	std::vector<SDL_Rect> slots;
};
