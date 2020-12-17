#pragma once
#include <SDL2/SDL.h>

namespace SDLlib
{
	class Rect
	{
	public:
		Rect();
		Rect(int x, int y, int width, int height);
		[[nodiscard]] constexpr int GetX() const {
			return rect_.x;
		}

		[[nodiscard]] constexpr int GetY() const {
			return rect_.y;
		}
		[[nodiscard]] constexpr int GetHeight() const {
			return rect_.h;
		}

		[[nodiscard]] constexpr int GetWidth() const {
			return rect_.w;
		}

		void SetX(int new_x);
		void SetY(int new_y);
		void SetWidth(int new_width);
		void SetHeight(int new_height);
		[[nodiscard]] SDL_Rect& Get();
	private:
		SDL_Rect rect_;
	};
}
