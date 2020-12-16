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
			throw Exception("IMG_Load");
		}
	}

	Surface::Surface(Surface&& rhs) noexcept : surface_(rhs.surface_)
	{
		rhs.surface_ = nullptr;
	}

	Surface& Surface::operator=(Surface&& rhs) noexcept
	{
		if (&rhs == this)
		{
			return *this;
		}
		if (surface_ != nullptr)
		{
			SDL_FreeSurface(surface_);
		}

		surface_ = rhs.surface_;
		rhs.surface_ = nullptr;
		return *this;
	}

	Surface::~Surface()
	{
		if (surface_ != nullptr)
		{
			SDL_FreeSurface(surface_);
			surface_ = nullptr;
		}
	}

	int Surface::GetWidth() const
	{
		return surface_->w;
	}

	int Surface::GetHeight() const
	{
		return surface_->h;
	}

	SDL_Surface* Surface::Get() const
	{
		return surface_;
	}
}
