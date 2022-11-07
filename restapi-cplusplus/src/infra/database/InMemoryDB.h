#pragma once

#include <vector>
#include "../../domain/entity/User.h"

class InMemoryDB
{
public:
	static std::vector<User> users;
};
