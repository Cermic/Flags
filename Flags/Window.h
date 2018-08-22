#pragma once
#include "SDL.h"

class Window
{
public:
	void RenderWindow();
	// Setters for Screen Size
	void SetScreenWidth(int sW) { screenHeight = sW; }
	void SetScreenHeight(int sH) { screenHeight = sH; }
	// Getters for Screen Size
	int GetScreenWidth() const { return screenWidth; }
	int GetScreenHeight() const { return screenHeight; }
private:
	SDL_Window * SetupRC(SDL_GLContext &context);
	bool HandleSDLEvent(SDL_Event const &sdlEvent);

	int screenWidth=0, screenHeight=0;
};
