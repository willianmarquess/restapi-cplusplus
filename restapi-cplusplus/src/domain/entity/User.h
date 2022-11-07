#pragma once

#include <string>

class User
{
private:
    std::string id;
    std::string email;
    std::string password;
public:
    User(std::string id, std::string email, std::string password);
    ~User();
    std::string getId();
    std::string getEmail();
    std::string getPassword();
    void setId(std::string id);
    void setEmail(std::string email);
    void setPassword(std::string password);
};