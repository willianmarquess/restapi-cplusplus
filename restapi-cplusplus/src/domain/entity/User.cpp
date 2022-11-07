#include "User.h"
#include "../../shared/util/uuid.h"

User::User(std::string id, std::string email, std::string password)
{
    std::string newid = uuid::generate_uuid_v4();
    this->id = id.empty() ? newid : id;
    this->email = email;
    this->password = password;
}

User::~User()
{
}

std::string User::getId() {
    return id;
}

std::string User::getEmail() {
    return email;
}

std::string User::getPassword() {
    return password;
}

void User::setId(std::string id) {
    this->id = id;
}

void User::setEmail(std::string email) {
    this->email = email;
}

void User::setPassword(std::string password) {
    this->password = password;
}
