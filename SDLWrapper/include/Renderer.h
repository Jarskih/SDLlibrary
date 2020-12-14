#pragma once
#include <SDL2/SDL.h>
#include "Window.h"

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
		void set_render_target(const Texture& texture) const;
		void set_render_draw_color(Color color) const;
		void render_copy(const Texture& texture) const;
		void render_clear() const;
		void render_present() const;
		[[nodiscard]] bool is_valid() const;
		[[nodiscard]] SDL_Renderer* get() const;
	private:
		SDL_Renderer* renderer_ = nullptr;
	};
}
