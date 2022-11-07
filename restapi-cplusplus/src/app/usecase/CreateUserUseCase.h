#pragma once

#include <memory>
#include "../../domain/repository/IUserRepository.h"
#include "../output/UserOutput.h"
#include "../../domain/entity/User.h"
#include "../mapper/UserMapper.h"
#include "ICreateUserUseCase.h"

class CreateUserUseCase : public ICreateUserUseCase
{
private:
    std::shared_ptr<IUserRepository> repository;
public:
    CreateUserUseCase(std::shared_ptr<IUserRepository> repository);
    ~CreateUserUseCase();
    UserOutput execute(CreateUserInput& createUserInput);
};
