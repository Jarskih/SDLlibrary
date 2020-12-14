#pragma once
#include <SDL2/SDL.h>

namespace SDLlib
{
	class SDL
	{
	public:
		explicit SDL(Uint32 flags);
		SDL(const SDL&) = delete;
		SDL(const SDL&&) = delete;
		SDL& operator=(const SDL&) = delete;
		SDL& operator=(const SDL&&) = delete;

		~SDL();
		[[nodiscard]] bool is_valid() const;
	private:
		Uint32 flags_ = 0;
	};
}
