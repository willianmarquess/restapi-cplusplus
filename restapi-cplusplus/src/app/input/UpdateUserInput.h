#pragma once

#include <string>

class UpdateUserInput
{
public:
    std::string id;
    std::string email;
    std::string password;
    UpdateUserInput(std::string id, std::string email, std::string password);
    ~UpdateUserInput();
};
