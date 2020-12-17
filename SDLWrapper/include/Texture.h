#pragma once
#include <SDL2/SDL.h>
#include <filesystem>

namespace SDLlib {
	class Surface;
	class Renderer;

	class Texture
	{
	public:
		Texture() = delete;
		Texture(const Renderer& renderer, Uint32 format, int access, int width, int height);
		Texture(const Renderer& renderer, std::filesystem::path file_path);
		Texture(const Texture& rhs) = delete;
		Texture(Texture&& rhs) = delete;
		Texture& operator=(const Texture& rhs) = delete;
		Texture& operator=(Texture&& rhs) = delete;
		~Texture();
		[[nodiscard]] bool IsValid() const;
		[[nodiscard]] SDL_Texture* Get() const;
		[[nodiscard]] int GetWidth() const;
		[[nodiscard]] int GetHeight() const;
	private:
		SDL_Texture* texture_ = nullptr;
		int width_{};
		int height_{};
	};
}
