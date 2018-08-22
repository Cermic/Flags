// Program entry point - SDL manages the actual WinMain entry point for us
#include "Game.h"
#include "Window.h"
#include "ScreenSlot.h"

int main(int argc, char *argv[]) {
	Window w;
	ScreenSlot screen;

	screen.InitialiseSlots(4);

	w.RenderWindow();

	return 0;
}