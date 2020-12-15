#include "Texture.h"

#include <filesystem>

#include "Renderer.h"
#include "Surface.h"
#include "Exception.h"
#include "WindowSize.h"

namespace SDLlib
{
	Texture::Texture(const Renderer& renderer, const Uint32 format, const int access, const int w, const int h)
	{
		texture_ = SDL_CreateTexture(renderer.get(), format, access, w, h);
		if (texture_ == nullptr)
		{
			throw Exception("SDL_CreateTexture");
		}
	}

	Texture::Texture(const Renderer& renderer, const std::filesystem::path file_path)
	{
		const Surface surface(file_path);
		texture_ = SDL_CreateTextureFromSurface(renderer.get(), surface.Get());
		if (texture_ == nullptr)
		{
			throw Exception("SDL_CreateTexture");
		}
		SDL_QueryTexture(texture_, nullptr, nullptr, &width_, &height_);
	}

	Texture::~Texture()
	{
		if (texture_ != nullptr)
		{
			SDL_DestroyTexture(texture_);
		}
	}

	bool Texture::IsValid() const
	{
		return texture_ != nullptr;
	}

	SDL_Texture* Texture::Get() const
	{
		return texture_;
	}

	Rectangle Texture::Size() const
	{
		return Rectangle(width_, height_);
	}
}
