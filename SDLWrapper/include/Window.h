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
		Window(const std::string& title, Point position, WindowSize size, Uint32 flags);
		~Window();
		[[nodiscard]] SDL_Window* get() const;
		bool is_valid() const;
	private:
		SDL_Window* window_ = nullptr;
	};
}
