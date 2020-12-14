#include "Window.h"
#include <SDL2/SDL.h>
#include "Exception.h"
#include "Point.h"
#include "WindowSize.h"

namespace SDLlib
{
	Window::Window(const std::string& title, const Point position, const WindowSize size, const Uint32 flags)
	{
		window_ = SDL_CreateWindow(title.c_str(), position.x, position.y, size.w, size.h, flags);
		if (window_ == nullptr)
		{
			throw Exception("SDL_CreateWindow");
		}
	}

	Window::~Window()
	{
		if (window_ != nullptr)
		{
			SDL_DestroyWindow(window_);
		}
	}

	SDL_Window* Window::get() const
	{
		return window_;
	}

	bool Window::is_valid() const
	{
		return window_ != nullptr;
	}
}
