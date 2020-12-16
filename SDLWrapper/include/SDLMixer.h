#pragma once
#include <SDL2/SDL_hints.h>

namespace SDLlib
{
	class SDLMixer
	{
	public:
		SDLMixer() = delete;
		explicit SDLMixer(int flags);
		SDLMixer(const SDLMixer&) = delete;
		SDLMixer(const SDLMixer&&) = delete;
		SDLMixer& operator=(const SDLMixer&) = delete;
		SDLMixer& operator=(const SDLMixer&&) = delete;
		~SDLMixer();
	private:
		Uint32 flags_ = 0;
	};
}
