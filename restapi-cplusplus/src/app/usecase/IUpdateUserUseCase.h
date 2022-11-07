#pragma once

#include "../output/UserOutput.h"
#include "../input/CreateUserInput.h"
#include "../input/UpdateUserInput.h"

class IUpdateUserUseCase
{
public:
    virtual UserOutput execute(UpdateUserInput& updateUserInput) = 0;
};
