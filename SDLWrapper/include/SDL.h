#pragma once
#include <SDL2/SDL.h>

namespace SDLlib
{
	class SDL
	{
	public:
		SDL() = delete;
		explicit SDL(Uint32 flags);
		SDL(const SDL&) = delete;
		SDL(const SDL&&) = delete;
		SDL& operator=(const SDL&) = delete;
		SDL& operator=(const SDL&&) = delete;
		~SDL();
		[[nodiscard]] bool IsValid() const;
	private:
		Uint32 flags_ = 0;
	};
}
