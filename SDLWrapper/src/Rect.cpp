#include "Rect.h"

namespace SDLlib
{
	Rect::Rect() : rect_{ 0, 0, 0, 0 }
	{
	}

	Rect::Rect(int x, int y, int width, int height) : rect_{ x, y, width, height }
	{
	}

	void Rect::SetX(int new_x)
	{
		rect_.x = new_x;
	}

	void Rect::SetY(int new_y)
	{
		rect_.y = new_y;
	}

	void Rect::SetWidth(int new_width)
	{
		rect_.w = new_width;
	}

	void Rect::SetHeight(int new_height)
	{
		rect_.h = new_height;
	}

	SDL_Rect& Rect::Get() {
		return rect_;
	}
}
