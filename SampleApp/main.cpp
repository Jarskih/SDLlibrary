#pragma comment(lib, "../build/Debug/SDLWrapper.lib")
#include <iostream>
#include "SDLlib.h"

int main(int, char* []) try {
	const SDLlib::SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
	const SDLlib::Window window("SampleApp", SDLlib::Point(0, 0), SDLlib::WindowSize(640, 480), SDL_WINDOW_SHOWN);
	const SDLlib::Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
	const SDLlib::Texture texture(renderer, "../assets/test.bmp");

	while (true)
	{
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				break;
			}
		}

		renderer.set_render_draw_color(SDLlib::Color(0, 0, 0, 0));
		renderer.render_clear();
		renderer.render_copy(texture);
		renderer.render_present();
	}

	return 0;
}
catch (std::exception& exception) {
	std::cerr << "Error: " << exception.what() << std::endl;
	return 1;
}
