#pragma comment(lib, "../build/Debug/SDLWrapper.lib")

#include <iostream>
#include "Entity.h"
#include "SDLlib.h"

// Wrap main function to try and catch to catch exceptions from the library

int main([[maybe_unused]] int, [[maybe_unused]] char* []) try {
	// Init SDL
	const SDLlib::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	const SDLlib::SDLMixer mixer(MIX_INIT_OGG | MIX_INIT_MP3);

	// Create window, renderer etc.
	const SDLlib::Window window("SampleApp", SDLlib::Rect(0, 0, 640, 480), SDL_WINDOW_SHOWN);
	const SDLlib::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);

	const SDLlib::Texture background(renderer, "../assets/bg.png");
	const SDLlib::Rect background_rect(0, 0, 640, 480);

	const Entity entity(renderer, SDLlib::Rect(200, 200, 100, 50), "../assets/entity.png");

	// Sound
	SDLlib::Sound sound("../assets/game1.wav");
	sound.PlayChannel(1, 0);
	sound.Pause();

	// Music
	const SDLlib::Music music("../assets/game1.wav");
	music.Play(1);

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
		renderer.RenderCopy(background, background_rect);
		entity.Render(renderer);
		renderer.RenderPresent();
	}

	return 0;
}
catch (std::exception& exception) {
	std::cerr << "Error: " << exception.what() << std::endl;
	return 1;
}