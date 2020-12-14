#include "Surface.h"
#include "Exception.h"
#include <SDL2/SDL_image.h>

namespace SDLlib
{
	Surface::Surface(const std::filesystem::path path)
	{
		surface_ = IMG_Load(path.string().c_str());
		if (surface_ == nullptr)
		{
			throw Exception("SDL_LoadBMP");
		}
	}

	Surface::~Surface()
	{
		SDL_FreeSurface(surface_);
	}

	SDL_Surface* Surface::get() const
	{
		return surface_;
	}
}
