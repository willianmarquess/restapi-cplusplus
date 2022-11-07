#pragma once

#include <string>

namespace CreateUserRequest {
	struct Body
	{
		std::string email;
		std::string password;
	};
};