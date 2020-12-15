#include "SDL.h"
#include "Exception.h"

namespace SDLlib
{
	SDL::SDL(const uint32_t flags) : flags_(flags)
	{
		if (SDL_Init(flags) != 0)
		{
			throw Exception("SDL_Init");
		}
	}

	SDL::~SDL()
	{
		SDL_Quit();
	}

	bool SDL::IsValid() const
	{
		return SDL_WasInit(flags_) != 0;
	}
}
