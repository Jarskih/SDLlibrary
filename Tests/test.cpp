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
		EXPECT_EQ(sdl.IsValid(), true);
	}

	TEST(Window, CreateWindow)
	{
		Window window("test", Point(0, 0), Rectangle(640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);
	}

	TEST(Window, IsBordered)
	{
		Window window("test", Point(0, 0), Rectangle(640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);
		window.SetWindowBordered(true);
		EXPECT_EQ(window.IsBordered(), true);

		window.SetWindowBordered(false);
		EXPECT_EQ(window.IsBordered(), false);
	}

	TEST(Window, Maximize)
	{
		Window window("test", Point(0, 0), Rectangle(640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);

		EXPECT_EQ(window.IsMaximized(), false);

		window.MaximizeWindow();
		EXPECT_EQ(window.IsMaximized(), true);
	}

	TEST(Window, Minimize)
	{
		Window window("test", Point(0, 0), Rectangle(640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);

		EXPECT_EQ(window.IsMinimized(), false);

		window.MinimizeWindow();
		EXPECT_EQ(window.IsMinimized(), true);
	}

	TEST(Window, Fullscreen)
	{
		Window window("test", Point(0, 0), Rectangle(640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);

		EXPECT_EQ(window.IsFullscreen(), false);

		const bool result1 = window.SetFullscreen(SDL_WINDOW_FULLSCREEN);
		EXPECT_EQ(result1, true);
		EXPECT_EQ(window.IsFullscreen(), true);

		const bool result2 = window.SetFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
		EXPECT_EQ(result2, true);
		EXPECT_EQ(window.IsFullscreen(), true);
	}

	TEST(Window, SetBrightness)
	{
		Window window("test", Point(0, 0), Rectangle(640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);
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
		const Window window("test", Point(0, 0), Rectangle(640, 480), 0);
		Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
		EXPECT_EQ(renderer.IsValid(), true);
	}

	TEST(Texture, CreateTexture)
	{
		const Window window("test", Point(0, 0), Rectangle(640, 480), 0);
		const Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
		const Texture texture(renderer, SDL_PIXELFORMAT_RGBA4444, SDL_TEXTUREACCESS_STATIC, 10, 10);
		EXPECT_EQ(texture.IsValid(), true);
	}
}