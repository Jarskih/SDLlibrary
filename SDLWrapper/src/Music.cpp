#include "Music.h"
#include "Exception.h"

namespace SDLlib
{
	Music::Music(std::string path)
	{
		music_ = Mix_LoadMUS(path.c_str());
		if (music_ == nullptr)
		{
			throw Exception("Mix_LoadMUS");
		}
	}

	Music::~Music()
	{
		if (music_ != nullptr)
		{
			Mix_FreeMusic(music_);
			music_ = nullptr;
		}
	}

	void Music::Play(int loops) const
	{
		Mix_PlayMusic(music_, loops);
	}

	void Music::Pause()
	{
		Mix_PauseMusic();
	}

	void Music::Resume()
	{
		Mix_ResumeMusic();
	}

	void Music::SetVolume(const unsigned volume)
	{
		const int vol = std::min(static_cast<int>(volume), 128);
		Mix_VolumeMusic(vol);
	}

	int Music::GetVolume()
	{
		return Mix_VolumeMusic(-1);
	}

	bool Music::IsValid() const
	{
		return music_ != nullptr;
	}
}
