#pragma once
#include <SDL2/SDL.h>

namespace SDLlib {
	class Color
	{
	public:
		Color(Uint8 r, Uint8 b, Uint8 g, Uint8 a);
		Uint8 r{};
		Uint8 b{};
		Uint8 g{};
		Uint8 a{};
	};
}
