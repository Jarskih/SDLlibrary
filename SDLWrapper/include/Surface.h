#pragma once
#include <filesystem>
#include <SDL2/SDL.h>

enum class ImageType;

namespace SDLlib
{
	class Surface
	{
	public:
		Surface(std::filesystem::path path);
		~Surface();
		SDL_Surface* get() const;
	private:
		SDL_Surface* surface_ = nullptr;
	};
}

