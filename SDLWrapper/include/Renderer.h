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
		Renderer(const Renderer& rhs) = delete;
		Renderer(Renderer&& rhs) noexcept;
		Renderer& operator=(const Renderer& rhs) = delete;
		Renderer& operator=(Renderer&& rhs) noexcept;
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
