#pragma once

class IDeleteUserUseCase
{
public:
    virtual void execute(std::string id) = 0;
};
