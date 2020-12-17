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
		Surface(const Surface& rhs) = delete;
		Surface(Surface&& rhs) noexcept;
		Surface& operator=(const Surface& rhs) = delete;
		Surface& operator=(Surface&& rhs) noexcept;
		~Surface();
		[[nodiscard]] int GetWidth() const;
		[[nodiscard]] int GetHeight() const;
		[[nodiscard]] SDL_Surface* Get() const;
	private:
		SDL_Surface* surface_ = nullptr;
	};
}

