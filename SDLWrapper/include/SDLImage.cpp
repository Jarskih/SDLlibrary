#include "SDLImage.h"
#include <SDL2/SDL_image.h>
#include "Exception.h"

SDLlib::SDLImage::SDLImage(const int flags) : flags_(flags)
{
	const int result = IMG_Init(flags_);
	if ((result & flags_) != flags_)
	{
		throw Exception("IMG_Init");
	}
}

bool SDLlib::SDLImage::IsValid(const int flags) const
{
	return flags_ & flags;
}

SDLlib::SDLImage::~SDLImage()
{
	IMG_Quit();
}
