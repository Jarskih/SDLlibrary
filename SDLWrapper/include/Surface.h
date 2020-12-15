#pragma once
#include <filesystem>
#include <SDL2/SDL.h>

enum class ImageType;

namespace SDLlib
{
	class Surface
	{
	public:
		Surface() = delete;
		Surface(std::filesystem::path path);
		Surface(const Surface&) = delete;
		Surface(const Surface&&) = delete;
		Surface& operator=(const Surface&) = delete;
		Surface& operator=(const Surface&&) = delete;
		~Surface();
		[[nodiscard]] SDL_Surface* Get() const;
	private:
		SDL_Surface* surface_ = nullptr;
	};
}

