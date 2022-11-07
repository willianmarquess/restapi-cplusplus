#pragma once

#include <memory>
#include <vector>
#include <iostream>
#include "../../domain/repository/IUserRepository.h"
#include "IGetAllUsersUseCase.h"
#include "../output/UserOutput.h"
#include "../../domain/entity/User.h"
#include "../mapper/UserMapper.h"

class GetAllUsersUseCase : public IGetAllUsersUseCase
{
private:
    std::shared_ptr<IUserRepository> repository;
public:
    GetAllUsersUseCase(std::shared_ptr<IUserRepository> repository);
    ~GetAllUsersUseCase();
    std::vector<UserOutput> execute();
};
