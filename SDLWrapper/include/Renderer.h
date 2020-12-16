#pragma once
#include <SDL2/SDL.h>

namespace SDLlib
{
	class Color;
	class Texture;
	class Window;

	class Renderer final
	{
	public:
		Renderer() = delete;
		Renderer(const Window& window, int driver_index, Uint32 flags);
		Renderer(const Renderer&) = delete;
		Renderer(const Renderer&&) = delete;
		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(const Renderer&&) = delete;
		~Renderer();
		void SetRenderTarget(const Texture& texture) const;
		void SetRenderDrawColor(const Color& color) const;
		void RenderCopy(const Texture& texture, SDL_Rect* source, SDL_Rect* destination) const;
		void RenderClear() const;
		void RenderPresent() const;
		[[nodiscard]] bool IsValid() const;
		[[nodiscard]] SDL_Renderer* get() const;
	private:
		SDL_Renderer* renderer_ = nullptr;
	};
}
