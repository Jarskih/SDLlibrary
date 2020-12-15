#pragma once
#include <SDL2/SDL.h>
#include <filesystem>

#include "WindowSize.h"

namespace SDLlib {
	class Surface;
	class Renderer;

	class Texture
	{
	public:
		Texture() = delete;
		Texture(const Renderer& renderer, Uint32 format, int access, int w, int h);
		Texture(const Renderer& renderer, std::filesystem::path file_path);
		Texture(const Texture&) = delete;
		Texture(const Texture&&) = delete;
		Texture& operator=(const Texture&) = delete;
		Texture& operator=(const Texture&&) = delete;
		~Texture();
		[[nodiscard]] bool IsValid() const;
		[[nodiscard]] SDL_Texture* Get() const;
		[[nodiscard]] Rectangle Size() const;
	private:
		SDL_Texture* texture_ = nullptr;
		int width_;
		int height_;
	};
}
