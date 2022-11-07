#pragma once

#include <memory>
#include "../../domain/repository/IUserRepository.h"
#include "IGetUserByIdUseCase.h"
#include "../output/UserOutput.h"
#include "../mapper/UserMapper.h"
#include "../../shared/error/NotFoundError.h"

class GetUserByIdUseCase : public IGetUserByIdUseCase
{
private:
    std::shared_ptr<IUserRepository> repository;
public:
    GetUserByIdUseCase(std::shared_ptr<IUserRepository> repository);
    ~GetUserByIdUseCase();
    UserOutput execute(std::string id);
};
