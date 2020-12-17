#include "Sound.h"
#include "Exception.h"

namespace SDLlib
{
	Sound::Sound(std::string path)
	{
		sound_ = Mix_LoadWAV(path.c_str());
		if (sound_ == nullptr)
		{
			throw Exception("Mix_LoadMUS");
		}
	}

	Sound::Sound(Sound&& rhs) noexcept : sound_(rhs.sound_)
	{
		rhs.sound_ = nullptr;
	}

	Sound& Sound::operator=(Sound&& rhs) noexcept
	{
		if (&rhs == this)
		{
			return *this;
		}
		if (sound_ != nullptr)
		{
			Mix_FreeChunk(sound_);
		}

		sound_ = rhs.sound_;
		rhs.sound_ = nullptr;
		return *this;
	}

	Sound::~Sound()
	{
		if (sound_ != nullptr)
		{
			Mix_FreeChunk(sound_);
			sound_ = nullptr;
		}
	}

	void Sound::PlayChannel(int channel, int loops)
	{
		channel_ = channel;
		Mix_PlayChannel(channel, sound_, loops);
	}

	void Sound::Pause() const
	{
		Mix_Pause(channel_);
	}

	void Sound::Resume() const
	{
		Mix_Resume(channel_);
	}

	void Sound::SetVolume(const unsigned volume) const
	{
		const int vol = std::min(static_cast<int>(volume), 128);
		Mix_VolumeMusic(vol);
	}

	bool Sound::IsPlaying() const
	{
		return Mix_Playing(channel_);
	}

	bool Sound::IsPlaused() const
	{
		return Mix_Paused(channel_);
	}

	int Sound::GetVolume() const
	{
		return Mix_VolumeMusic(-1);
	}

	Mix_Chunk* Sound::GetChunk() const
	{
		return Mix_GetChunk(channel_);
	}

	bool Sound::IsValid() const
	{
		return sound_ != nullptr;
	}
}
