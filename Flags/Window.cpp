#include "Window.h"
#include "glew.h"
#include <iostream>
#include "ScreenSlot.h"

SDL_Window * Window::SetupRC(SDL_GLContext & context)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) // Initialize video
	{
		std::cout << "Unable to initialize SDL";
		exit(1);
	}

	// Request an OpenGL 3.0 context.

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);  // double buffering on
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8); // 8 bit alpha buffering
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 4); // Turn on x4 multisampling anti-aliasing (MSAA)

													   // Create 1920x1080 window
	SDL_DisplayMode DM;
	SDL_GetCurrentDisplayMode(0, &DM);
	screenWidth = DM.w - 20;
	screenHeight = DM.h - 62;
	SDL_Window * window = SDL_CreateWindow("Flags Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		screenWidth, screenHeight, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	// Setup renderer
	SDL_Renderer* renderer = nullptr;
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// Set render color to red ( background will be rendered in this color )
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	// Clear winow
	SDL_RenderClear(renderer);

	if (!window) // Check window was created OK
	{
		std::cout << "Unable to initialize SDL";
		exit(1);
	}
	context = SDL_GL_CreateContext(window); // Create opengl context and attach to window
	SDL_GL_SetSwapInterval(1); // set swap buffers to sync with monitor's vertical refresh rate
	return window;
}

bool Window::HandleSDLEvent(SDL_Event const & sdlEvent)
{
	if (sdlEvent.type == SDL_QUIT)
	{
		return false;
	}

	if (sdlEvent.type == SDL_KEYDOWN)
	{
		// Can extend this to handle a wider range of keys
		switch (sdlEvent.key.keysym.sym)
		{
		case SDLK_ESCAPE:
			return false;
		default:
			break;
		}
	}
}

void Window::RenderWindow()
{
	SDL_Window * hWindow; // window handle
	SDL_GLContext glContext; // OpenGL context handle
	hWindow = SetupRC(glContext); // Create window and render context 

								  // Required on Windows *only* init GLEW to access OpenGL beyond 1.1
	glewExperimental = GL_TRUE;
	GLenum err = glewInit();
	if (GLEW_OK != err) { // glewInit failed, something is seriously wrong
		std::cout << "glewInit failed, aborting." << std::endl;
		exit(1);
	}
	std::cout << glGetString(GL_VERSION) << std::endl;

	bool running = true; // set running to true
	SDL_Event sdlEvent;  // variable to detect SDL events
	ScreenSlot screen;
	while (running)
	{
		SDL_PollEvent(&sdlEvent);
		screen.RenderSlots();
		running = HandleSDLEvent(sdlEvent);// the event loop - This loop allows ESCAPE to be pressed to exit the event loop.
	}

	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(hWindow);
	SDL_Quit();
}
