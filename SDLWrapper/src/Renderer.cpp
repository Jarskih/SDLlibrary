#include "Renderer.h"
#include "Color.h"
#include "Exception.h"
#include "Rect.h"
#include "Window.h"
#include "Texture.h"

namespace SDLlib
{
	Renderer::Renderer(const Window& window, const int driver_index, const Uint32 flags)
	{
		renderer_ = SDL_CreateRenderer(window.Get(), driver_index, flags);
		if (renderer_ == nullptr)
		{
			throw Exception("SDL_CreateRenderer");
		}
	}

	Renderer::Renderer(Renderer&& rhs) noexcept : renderer_(rhs.renderer_)
	{
		rhs.renderer_ = nullptr;
	}

	Renderer& Renderer::operator=(Renderer&& rhs) noexcept
	{
		if (&rhs == this)
		{
			return *this;
		}
		if (renderer_ != nullptr)
		{
			SDL_DestroyRenderer(renderer_);
		}

		renderer_ = rhs.renderer_;
		rhs.renderer_ = nullptr;
		return *this;
	}

	Renderer::~Renderer()
	{
		if (renderer_ != nullptr)
		{
			SDL_DestroyRenderer(renderer_);
			renderer_ = nullptr;
		}
	}

	void Renderer::SetRenderTarget(const Texture& texture) const
	{
		SDL_SetRenderTarget(renderer_, texture.Get());
	}

	void Renderer::SetRenderDrawColor(const Color& color) const
	{
		SDL_SetRenderDrawColor(renderer_, color.r, color.g, color.b, color.a);
	}

	void Renderer::RenderCopy(const Texture& texture, Rect source, Rect destination) const
	{
		SDL_RenderCopy(renderer_, texture.Get(), &source.Get(), &destination.Get());
	}

	void Renderer::RenderCopy(const Texture& texture, Rect source) const
	{
		SDL_RenderCopy(renderer_, texture.Get(), &source.Get(), nullptr);
	}

	void Renderer::RenderClear() const
	{
		SDL_RenderClear(renderer_);
	}

	void Renderer::RenderPresent() const
	{
		SDL_RenderPresent(renderer_);
	}

	bool Renderer::IsValid() const
	{
		return renderer_ != nullptr;
	}

	SDL_Renderer* Renderer::get() const
	{
		return renderer_;
	}
}
