#include "Window.h"
#include "ScreenSlot.h"
#include <iostream>
#include <glew.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

void ScreenSlot::InitialiseSlots(int numberOfSlots)
{
	Window window;
	//Space reserved for the vector
	slots.reserve(numberOfSlots);
	slots.resize(numberOfSlots);

	slots.at(0).w = 200;
	slots.at(0).h = 200;

	slots.at(0).x = -window.GetScreenWidth() + 20;
	slots.at(0).y = -window.GetScreenHeight() - 50;

	std::cout << "Slot 0 Initialised " << std::endl;
	//Example of initialising a slot - can be done in a loop for the 4 options or another elegant way later.
}

void ScreenSlot::RenderSlots()
{
	
}
