#include "Texture.h"

#include <filesystem>
#include "Renderer.h"
#include "Surface.h"
#include "Exception.h"

namespace SDLlib
{
	Texture::Texture(const Renderer& renderer, const Uint32 format, const int access, const int width, const int height)
	{
		texture_ = SDL_CreateTexture(renderer.get(), format, access, width, height);
		if (texture_ == nullptr)
		{
			throw Exception("SDL_CreateTexture");
		}
		SDL_QueryTexture(texture_, nullptr, nullptr, &width_, &height_);
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
			texture_ = nullptr;
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

	int Texture::GetWidth() const
	{
		return width_;
	}

	int Texture::GetHeight() const
	{
		return height_;
	}
}
