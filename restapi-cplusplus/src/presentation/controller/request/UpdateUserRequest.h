#pragma once

#include <string>

namespace UpdateUserRequest {
	struct Body
	{
		std::string email;
		std::string password;
	};

	struct Params
	{
		std::string id;
	};
};