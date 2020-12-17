#pragma once
#include <SDL2/SDL_hints.h>

namespace SDLlib
{
	class SDLMixer
	{
	public:
		SDLMixer() = delete;
		explicit SDLMixer(int flags);
		SDLMixer(const SDLMixer& rhs) = delete;
		SDLMixer(SDLMixer&& rhs) = delete;
		SDLMixer& operator=(const SDLMixer& rhs) = delete;
		SDLMixer& operator=(SDLMixer&& rhs) = delete;
		~SDLMixer();
	private:
		Uint32 flags_ = 0;
	};
}
