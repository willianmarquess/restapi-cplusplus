#include "UserRepository.h"

UserRepository::UserRepository()
{

}
UserRepository::~UserRepository()
{
    std::cout << "user repository destroyed";
}

User& UserRepository::create(User& user)
{
    InMemoryDB::users.push_back(user);
    return user;
}

std::vector<User> UserRepository::getUsers()
{
    return InMemoryDB::users;
}

std::optional<User> UserRepository::getUserById(std::string id) {
    for (auto& user: InMemoryDB::users)
    {
        if (user.getId() == id) {
            return user;
        }
    }
    return {};
}

User& UserRepository::update(User& userToUpdate)
{
    for (auto& user : InMemoryDB::users)
    {
        if (user.getId() == userToUpdate.getId()) {
            user.setEmail(userToUpdate.getEmail());
            user.setPassword(userToUpdate.getPassword());
            return user;
        }
    }
    return userToUpdate;
}

void UserRepository::deleteById(std::string id) {
    for (int i = 0; InMemoryDB::users.size(); ++i) {
        if (InMemoryDB::users[i].getId() == id) {
            InMemoryDB::users.erase(InMemoryDB::users.begin()+i);
        }
    }
}