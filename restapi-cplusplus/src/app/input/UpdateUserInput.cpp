#include "UpdateUserInput.h"

UpdateUserInput::UpdateUserInput(std::string id, std::string email, std::string password)
{
    this->id = id;
    this->email = email;
    this->password = password;
}

UpdateUserInput::~UpdateUserInput()
{
}