#pragma once
#include <SDL2/SDL.h>
#include <string>
#include "Point.h"
#include "WindowSize.h"

namespace SDLlib
{
	struct WindowSize;
	struct Point;

	class Window
	{
	public:
		Window() = delete;
		Window(const std::string& title, Point position, WindowSize size, Uint32 flags);
		Window(const Window&) = delete;
		Window(const Window&&) = delete;
		Window& operator=(const Window&) = delete;
		Window& operator=(const Window&&) = delete;
		~Window();
		[[nodiscard]] SDL_Window* get() const;
		[[nodiscard]] bool is_valid() const;
	private:
		SDL_Window* window_ = nullptr;
	};
}
