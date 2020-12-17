#include "pch.h"
#include "SDLlib.h"
#include "Sound.h"

namespace SDLlib
{
	TEST(SDL, Constructor)
	{
		SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		EXPECT_EQ(sdl.IsValid(), true);
	}

	TEST(Window, Constructor)
	{
		Window window("test", Rect(0, 0, 640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);
	}

	TEST(Window, SetBordered)
	{
		Window window("test", Rect(0, 0, 640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);
		window.SetWindowBordered(true);
		EXPECT_EQ(window.IsBordered(), true);

		window.SetWindowBordered(false);
		EXPECT_EQ(window.IsBordered(), false);
	}

	TEST(Window, Maximize)
	{
		Window window("test", Rect(0, 0, 640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);

		EXPECT_EQ(window.IsMaximized(), false);

		window.MaximizeWindow();
		EXPECT_EQ(window.IsMaximized(), true);
	}

	TEST(Window, Minimize)
	{
		Window window("test", Rect(0, 0, 640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);

		EXPECT_EQ(window.IsMinimized(), false);

		window.MinimizeWindow();
		EXPECT_EQ(window.IsMinimized(), true);
	}

	TEST(Window, Fullscreen)
	{
		Window window("test", Rect(0, 0, 640, 480), 0);
		EXPECT_EQ(window.IsValid(), true);

		EXPECT_EQ(window.IsFullscreen(), false);

		const bool result1 = window.SetFullscreen(SDL_WINDOW_FULLSCREEN);
		EXPECT_EQ(result1, true);
		EXPECT_EQ(window.IsFullscreen(), true);

		const bool result2 = window.SetFullscreen(SDL_WINDOW_FULLSCREEN_DESKTOP);
		EXPECT_EQ(result2, true);
		EXPECT_EQ(window.IsFullscreen(), true);
	}

	TEST(Renderer, Constructor)
	{
		const Window window("test", Rect(0, 0, 640, 480), 0);
		Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
		EXPECT_EQ(renderer.IsValid(), true);
	}

	TEST(Texture, Constructor)
	{
		const Window window("test", Rect(0, 0, 640, 480), 0);
		const Renderer renderer(window, -1, SDL_RENDERER_ACCELERATED);
		const Texture texture1(renderer, SDL_PIXELFORMAT_RGBA4444, SDL_TEXTUREACCESS_STATIC, 10, 10);
		EXPECT_EQ(texture1.IsValid(), true);

		const Texture texture2(renderer, "../../assets/entity.png");
		EXPECT_EQ(texture2.IsValid(), true);
	}

	TEST(Music, Constructor)
	{
		SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		EXPECT_EQ(sdl.IsValid(), true);

		SDLMixer mixer(MIX_INIT_MP3);

		Music music("../../assets/game1.wav");
		EXPECT_EQ(music.IsValid(), true);
	}

	TEST(Sound, Constructor)
	{
		SDL sdl(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
		EXPECT_EQ(sdl.IsValid(), true);

		SDLMixer mixer(MIX_INIT_MP3);

		Sound sound("../../assets/game1.wav");
		EXPECT_EQ(sound.IsValid(), true);
	}
}
