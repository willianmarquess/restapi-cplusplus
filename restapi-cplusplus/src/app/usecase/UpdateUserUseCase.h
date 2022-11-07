#pragma once

#include <memory>
#include "IUpdateUserUseCase.h"
#include "../../domain/repository/IUserRepository.h"
#include "../mapper/UserMapper.h"

class UpdateUserUseCase : public IUpdateUserUseCase
{
private:
	std::shared_ptr<IUserRepository> repository;

public:
	UpdateUserUseCase(std::shared_ptr<IUserRepository> repository);
	~UpdateUserUseCase();
	UserOutput execute(UpdateUserInput& updateUserInput);
};