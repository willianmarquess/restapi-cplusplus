#pragma once

#include <vector>
#include <iostream>
#include "../../domain/repository/IUserRepository.h"
#include "../../domain/entity/User.h"
#include "../database/InMemoryDB.h"

class UserRepository : public IUserRepository
{
public:
    UserRepository();
    ~UserRepository();
    User& create(User& user);
    std::vector<User> getUsers();
    std::optional<User> getUserById(std::string id);
    User& update(User& user);
    void deleteById(std::string id);
    std::optional<User> getByEmail(std::string email);
};
