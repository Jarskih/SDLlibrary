#pragma once

namespace SDLlib
{
	class SDLImage
	{
	public:
		SDLImage() = delete;
		explicit SDLImage(int flags);
		SDLImage(const SDLImage&) = delete;
		SDLImage(const SDLImage&&) = delete;
		SDLImage& operator=(const SDLImage&) = delete;
		SDLImage& operator=(const SDLImage&&) = delete;
		~SDLImage();
		[[nodiscard]] bool IsValid(int flags) const;
	private:
		int flags_ = 0;
	};
}
