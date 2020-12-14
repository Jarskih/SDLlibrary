#include "pch.h"
#include <filesystem>
#include "Renderer.h"
#include "SDL.h"
#include <SDL2/SDL.h>
#include "Texture.h"
#include "Window.h"

namespace SDLlib
{
	TEST(Init_SDL, IsValid)
	{
		SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		EXPECT_EQ(sdl.is_valid(), true);
	}
	TEST(CreateWindow, IsValid)
	{
		Window window("test", SDLlib::Point(0, 0), SDLlib::WindowSize(640, 480), 0);
		EXPECT_EQ(window.is_valid(), true);
	}

	TEST(CreateRenderer, IsValid)
	{
		const Window window("test", SDLlib::Point(0, 0), SDLlib::WindowSize(640, 480), 0);
		Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
		EXPECT_EQ(renderer.is_valid(), true);
	}

	TEST(CreateTexture, IsValid)
	{
		const Window window("test", SDLlib::Point(0, 0), SDLlib::WindowSize(640, 480), 0);
		const Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
		std::filesystem::path path("../assets/test.bmp");
		const Texture texture(renderer, path);
		EXPECT_EQ(texture.is_valid(), true);
	}
}