#pragma once

#include <memory>
#include "../controller/UserController.h"
#include "../../app/usecase/CreateUserUseCase.h";
#include "../../app/usecase/GetAllUsersUseCase.h";
#include "../../app/usecase/GetUserByIdUseCase.h";
#include "../../infra/repository/UserRepository.h"
#include "../../app/usecase/UpdateUserUseCase.h"
#include "../../app/usecase/DeleteUserUseCase.h"

class UserControllerFactory
{
public:
	static std::shared_ptr<IUserController> create() {
		std::shared_ptr<IUserRepository> repository = std::make_shared<UserRepository>();
		std::shared_ptr<IGetAllUsersUseCase> getAllUsersUseCase = std::make_shared<GetAllUsersUseCase>(repository);
		std::shared_ptr<ICreateUserUseCase> createUserUseCase = std::make_shared<CreateUserUseCase>(repository);
		std::shared_ptr<IGetUserByIdUseCase> getUserByIdUseCase = std::make_shared<GetUserByIdUseCase>(repository);
		std::shared_ptr<IUpdateUserUseCase> updateUserUseCase = std::make_shared<UpdateUserUseCase>(repository);
		std::shared_ptr<IDeleteUserUseCase> deleteUserUseCase = std::make_shared<DeleteUserUseCase>(repository);
		std::shared_ptr<UserController> controller = std::make_shared<UserController>(createUserUseCase, getAllUsersUseCase, getUserByIdUseCase, updateUserUseCase, deleteUserUseCase);
		return controller;
	}
};
