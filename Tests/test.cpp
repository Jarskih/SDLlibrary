#include "pch.h"
#include <filesystem>
#include "Renderer.h"
#include "SDL.h"
#include <SDL2/SDL.h>
#include "Texture.h"
#include "Window.h"

namespace SDLlib
{
	TEST(SDL, Init)
	{
		SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		EXPECT_EQ(sdl.is_valid(), true);
	}
	TEST(Window, CreateWindow)
	{
		Window window("test", Point(0, 0), WindowSize(640, 480), 0);
		EXPECT_EQ(window.is_valid(), true);
	}

	TEST(Window, IsBordered)
	{
		Window window("test", Point(0, 0), WindowSize(640, 480), 0);
		EXPECT_EQ(window.is_valid(), true);
		window.SetWindowBordered(true);
		EXPECT_EQ(window.IsWindowBordered(), true);

		window.SetWindowBordered(false);
		EXPECT_EQ(window.IsWindowBordered(), false);
	}

	TEST(Window, Maximize)
	{
		Window window("test", Point(0, 0), WindowSize(640, 480), 0);
		EXPECT_EQ(window.is_valid(), true);

		EXPECT_EQ(window.IsWindowMaximized(), false);

		window.MaximizeWindow();
		EXPECT_EQ(window.IsWindowMaximized(), true);
	}

	TEST(Window, Minimize)
	{
		Window window("test", Point(0, 0), WindowSize(640, 480), 0);
		EXPECT_EQ(window.is_valid(), true);

		EXPECT_EQ(window.IsWindowMinimized(), false);

		window.MinimizeWindow();
		EXPECT_EQ(window.IsWindowMinimized(), true);
	}

	TEST(Window, Raise)
	{
		Window window("test", Point(0, 0), WindowSize(640, 480), 0);
		EXPECT_EQ(window.is_valid(), true);

		EXPECT_EQ(window.IsWindowRaised(), false);

		window.RaiseWindow();
		EXPECT_EQ(window.IsWindowRaised(), true);
	}
	TEST(Window, SetBrightness)
	{
		Window window("test", Point(0, 0), WindowSize(640, 480), 0);
		EXPECT_EQ(window.is_valid(), true);
		bool result1 = window.SetWindowBrightness(0.0);
		EXPECT_EQ(result1, true);

		bool result2 = window.SetWindowBrightness(1.0);
		EXPECT_EQ(result2, true);

		bool result3 = window.SetWindowBrightness(2.0);
		EXPECT_EQ(result3, true);

		bool result4 = window.SetWindowBrightness(-1.0);
		EXPECT_EQ(result4, true);

		bool result5 = window.SetWindowBrightness(100.0);
		EXPECT_EQ(result5, true);
	}

	TEST(Renderer, CreateRenderer)
	{
		const Window window("test", Point(0, 0), WindowSize(640, 480), 0);
		Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
		EXPECT_EQ(renderer.is_valid(), true);
	}

	TEST(Texture, CreateTexture)
	{
		const Window window("test", Point(0, 0), WindowSize(640, 480), 0);
		const Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
		std::filesystem::path path("../assets/test.bmp");
		const Texture texture(renderer, path);
		EXPECT_EQ(texture.is_valid(), true);
	}
}