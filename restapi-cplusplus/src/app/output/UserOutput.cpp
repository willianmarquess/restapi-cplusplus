#include "UserOutput.h"

UserOutput::UserOutput(std::string id, std::string email, std::string password)
{
    this->id = id;
    this->email = email;
    this->password = password;
}

UserOutput::~UserOutput()
{
}
