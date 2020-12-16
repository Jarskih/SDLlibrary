#include "Window.h"
#include <SDL2/SDL.h>
#include "Exception.h"

namespace SDLlib
{
	Window::Window(const std::string& title, const SDL_Rect rectangle, const Uint32 flags)
	{
		window_ = SDL_CreateWindow(title.c_str(), rectangle.x, rectangle.y, rectangle.w, rectangle.h, flags);
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
			window_ = nullptr;
		}
	}

	SDL_Window* Window::Get() const
	{
		return window_;
	}

	bool Window::IsValid() const
	{
		return window_ != nullptr;
	}

	bool Window::IsBordered() const
	{
		const int flags = SDL_GetWindowFlags(window_);
		return !(flags & SDL_WINDOW_BORDERLESS);
	}

	bool Window::IsMaximized() const
	{
		const int flags = SDL_GetWindowFlags(window_);
		return flags & SDL_WINDOW_MAXIMIZED;
	}

	bool Window::IsMinimized() const
	{
		const int flags = SDL_GetWindowFlags(window_);
		return flags & SDL_WINDOW_MINIMIZED;
	}

	bool Window::IsFullscreen() const
	{
		const int flags = SDL_GetWindowFlags(window_);
		return flags & SDL_WINDOW_FULLSCREEN || flags & SDL_WINDOW_FULLSCREEN_DESKTOP;
	}

	void Window::MaximizeWindow() const
	{
		SDL_MaximizeWindow(window_);
	}

	void Window::MinimizeWindow() const
	{
		SDL_MinimizeWindow(window_);
	}
	void Window::RaiseWindow() const
	{
		SDL_RaiseWindow(window_);
	}

	void Window::RestoreWindow() const
	{
		SDL_RestoreWindow(window_);
	}

	void Window::SetWindowBordered(bool is_bordered) const
	{
		SDL_SetWindowBordered(window_, static_cast<SDL_bool>(is_bordered));
	}

	bool Window::SetWindowDisplayMode(SDL_DisplayMode* display_mode) const
	{
		const int result = SDL_SetWindowDisplayMode(window_, display_mode);
		return result == 0 ? true : false;
	}

	bool Window::SetFullscreen(Uint32 flags) const
	{
		const int result = SDL_SetWindowFullscreen(window_, flags);
		return result == 0 ? true : false;
	}

	void Window::SetWindowPosition(int x, int y) const
	{
		SDL_SetWindowPosition(window_, x, y);
	}

	void Window::SetWindowSize(const int width, const int height) const
	{
		SDL_SetWindowSize(window_, width, height);
	}

	void Window::SetWindowTitle(const std::string& title) const
	{
		SDL_SetWindowTitle(window_, title.c_str());
	}
}
