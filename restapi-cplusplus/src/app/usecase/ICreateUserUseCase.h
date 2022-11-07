#pragma once

#include "../output/UserOutput.h"
#include "../input/CreateUserInput.h"

class ICreateUserUseCase
{
public:
    virtual UserOutput execute(CreateUserInput& createUserInput) = 0;
};
