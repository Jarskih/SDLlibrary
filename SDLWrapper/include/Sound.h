#pragma once
#include "SDLlib.h"
#include <string>

namespace SDLlib
{
	class Sound
	{
	public:
		Sound() = delete;
		explicit Sound(std::string path);
		Sound(const Sound& rhs) = delete;
		Sound(Sound&& rhs) noexcept;
		Sound& operator=(const Sound& rhs) = delete;
		Sound& operator=(Sound&& rhs) noexcept;
		~Sound();
		void PlayChannel(int channel, int loops);
		void Pause() const;
		void Resume() const;
		[[nodiscard]] bool IsPlaying() const;
		[[nodiscard]] bool IsPlaused() const;
		[[nodiscard]] static int GetVolume();
		[[nodiscard]] Mix_Chunk* GetChunk() const;
		[[nodiscard]] bool IsValid() const;
		static void SetVolume(unsigned int volume);
	private:
		Mix_Chunk* sound_{};
		int channel_{};
		std::string path_{};
	};
}
