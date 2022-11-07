#pragma once

#include <memory>
#include "../../domain/repository/IUserRepository.h"
#include "IDeleteUserUseCase.h"
#include "../../shared/error/NotFoundError.h"

class DeleteUserUseCase : public IDeleteUserUseCase
{
private:
    std::shared_ptr<IUserRepository> repository;
public:
    DeleteUserUseCase(std::shared_ptr<IUserRepository> repository);
    ~DeleteUserUseCase();
    void execute(std::string id);
};