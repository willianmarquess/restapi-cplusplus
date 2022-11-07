#pragma once

#include <vector>
#include <optional>
#include "../entity/User.h"

class IUserRepository
{
public:
    virtual User& create(User& user) = 0;
    virtual std::vector<User> getUsers() = 0;
    virtual std::optional<User> getUserById(std::string id) = 0;
    virtual User& update(User& user) = 0;
    virtual void deleteById(std::string id) = 0;
};