#include "Exception.h"
#include <SDL2/SDL.h>

namespace SDLlib
{
	Exception::Exception(const char* function)
		: std::runtime_error(CreateErrorMessage(function, SDL_GetError()))
		, function_(function)
		, error_(SDL_GetError()) {
	}

	std::string Exception::CreateErrorMessage(const char* function, const char* error) {
		std::string message(function);
		message += " error: ";
		message += error;
		return message;
	}

	std::string Exception::GetFunction() const
	{
		return function_;
	}

	std::string Exception::GetError() const
	{
		return error_;
	}
}
