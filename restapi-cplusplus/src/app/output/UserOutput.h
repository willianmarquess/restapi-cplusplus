#pragma once

#include <string>

class UserOutput
{
public:
    std::string id;
    std::string email;
    std::string password;
    UserOutput(std::string id, std::string email, std::string password);
    ~UserOutput();
};
