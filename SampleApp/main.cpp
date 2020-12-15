#pragma comment(lib, "../build/Debug/SDLWrapper.lib")

#include <iostream>

#include "Entity.h"
#include "SDLlib.h"

// Wrap main function to try and catch to catch exceptions from the library

int main([[maybe_unused]] int, [[maybe_unused]] char* []) try {
	// Init SDL
	const SDLlib::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);

	// Create window, renderer etc.
	const SDLlib::Window window("SampleApp", SDLlib::Point(0, 0), SDLlib::Rectangle(640, 480), SDL_WINDOW_SHOWN);
	const SDLlib::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

	const Entity entity(renderer, SDL_Point{ 400,200 }, SDLlib::Rectangle(100, 100), "../assets/entity.png");

	while (true)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				break;
			}
		}

		renderer.SetRenderDrawColor(SDLlib::Color(0, 0, 0, 0));
		renderer.RenderClear();
		entity.Render(renderer);
		renderer.RenderPresent();
	}

	return 0;
}
catch (std::exception& exception) {
	std::cerr << "Error: " << exception.what() << std::endl;
	return 1;
}
