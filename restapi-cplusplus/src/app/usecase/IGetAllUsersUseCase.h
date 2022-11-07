#pragma once

#include <vector>
#include "../output/UserOutput.h"

class IGetAllUsersUseCase
{
public:
    virtual std::vector<UserOutput> execute() = 0;
};
