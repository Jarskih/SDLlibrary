#pragma once
#include <stdexcept>

namespace SDLlib
{
	class Exception final : public std::runtime_error
	{
	public:
		Exception() = delete;
		explicit Exception(const char* function);
		virtual ~Exception() noexcept = default;
		static std::string create_error_message(const char* function, const char* error);
		[[nodiscard]] std::string get_function() const;
		[[nodiscard]] std::string get_error() const;
	private:
		std::string function_;
		std::string error_;
	};
}
