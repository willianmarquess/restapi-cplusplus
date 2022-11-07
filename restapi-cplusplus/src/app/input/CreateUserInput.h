#pragma once

#include <string>

class CreateUserInput
{
public:
    std::string email;
    std::string password;
    CreateUserInput(std::string email, std::string password);
    ~CreateUserInput();
};
