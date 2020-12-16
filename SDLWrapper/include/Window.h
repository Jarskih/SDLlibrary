#pragma once
#include <SDL2/SDL.h>
#include <string>

namespace SDLlib
{
	struct Rectangle;
	struct Point;

	class Window
	{
	public:
		Window() = delete;
		Window(const std::string& title, SDL_Rect rectangle, Uint32 flags);
		Window(Window&) = delete;
		Window(Window&&) noexcept;
		Window& operator=(const Window&) = delete;
		Window& operator=(Window&&) noexcept;
		~Window();
		[[nodiscard]] SDL_Window* Get() const;
		[[nodiscard]] bool IsValid() const;
		[[nodiscard]] bool IsBordered() const;
		[[nodiscard]] bool IsMaximized() const;
		[[nodiscard]] bool IsMinimized() const;
		[[nodiscard]] bool IsFullscreen() const;
		void MaximizeWindow() const;
		void MinimizeWindow() const;
		void RaiseWindow() const;
		void RestoreWindow() const;
		void SetWindowBordered(bool is_bordered) const;
		bool SetWindowDisplayMode(SDL_DisplayMode* display_mode) const;
		bool SetFullscreen(Uint32 flags) const;
		void SetWindowPosition(int x, int y) const;
		void SetWindowSize(int width, int height) const;
		void SetWindowTitle(const std::string& title) const;

	private:
		SDL_Window* window_ = nullptr;
	};
}
