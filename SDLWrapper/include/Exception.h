#pragma once
#include <stdexcept>

namespace SDLlib
{
	class Exception final : public std::runtime_error
	{
	public:
		Exception() = delete;
		explicit Exception(const char* function);
		Exception(Exception&) = delete;
		Exception(Exception&&) = delete;
		Exception& operator=(const Exception&) = delete;
		Exception& operator=(Exception&&) = delete;
		virtual ~Exception() noexcept = default;
		static std::string CreateErrorMessage(const char* function, const char* error);
		[[nodiscard]] std::string GetFunction() const;
		[[nodiscard]] std::string GetError() const;
	private:
		std::string function_;
		std::string error_;
	};
}
