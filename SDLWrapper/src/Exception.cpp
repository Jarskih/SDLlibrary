#include "Exception.h"
#include <SDL2/SDL.h>

namespace SDLlib
{
	Exception::Exception(const char* function)
		: std::runtime_error(create_error_message(function, SDL_GetError()))
		, function_(function)
		, error_(SDL_GetError()) {
	}

	std::string Exception::create_error_message(const char* function, const char* error) {
		std::string message(function);
		message += " error: ";
		message += error;
		return message;
	}

	std::string Exception::get_function() const
	{
		return function_;
	}

	std::string Exception::get_error() const
	{
		return error_;
	}
}
