#pragma once

#include "../output/UserOutput.h"

class IGetUserByIdUseCase
{
public:
    virtual UserOutput execute(std::string id) = 0;
};
