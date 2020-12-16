#include "SDLMixer.h"

#include "Exception.h"
#include "SDLlib.h"

namespace SDLlib {

	SDLMixer::SDLMixer(const int flags) : flags_(flags)
	{
		Mix_Init(flags);
		const int openAudio = Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);

		if (openAudio == -1) {
			throw Exception("Mix_OpenAudio");
		}
	}

	SDLMixer::~SDLMixer()
	{
		Mix_CloseAudio();
		Mix_Quit();
	}
}