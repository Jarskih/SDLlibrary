#pragma once
#include "SDLlib.h"
#include <string>

namespace SDLlib
{
	class Music
	{
	public:
		Music() = delete;
		explicit Music(std::string path);
		~Music();
		void Play(int loops) const;
		void Pause();
		void Resume();
		void SetVolume(unsigned int volume);
		int GetVolume();
		bool IsValid() const;
	private:
		Mix_Music* music_{};
	};
}
