#pragma once

#include <memory>
#include <tuple>
#include <optional>
#include "IUserController.h"
#include "../../app/usecase/ICreateUserUseCase.h"
#include "../../app/usecase/IGetAllUsersUseCase.h"
#include "../../app/usecase/IGetUserByIdUseCase.h"
#include "../../app/usecase/IUpdateUserUseCase.h"
#include "../../shared/util/InstanceOf.h"
#include "helper/HttpHelper.h"
#include "response/ErrorResponse.h"
#include "../../shared/error/NotFoundError.h"
#include "../../app/input/UpdateUserInput.h"
#include "../../app/usecase/IDeleteUserUseCase.h"

class UserController : public IUserController
{
private:
	std::shared_ptr<ICreateUserUseCase> createUseCase;
	std::shared_ptr<IGetAllUsersUseCase> getAllUsersUseCase;
	std::shared_ptr<IGetUserByIdUseCase> getUserByIdUseCase;
	std::shared_ptr<IUpdateUserUseCase> updateUserUseCase;
	std::shared_ptr<IDeleteUserUseCase> deleteUserUseCase;
public:
	UserController(std::shared_ptr<ICreateUserUseCase> createUseCase, std::shared_ptr<IGetAllUsersUseCase> getAllUsersUseCase, std::shared_ptr<IGetUserByIdUseCase> getUserByIdUseCase, std::shared_ptr<IUpdateUserUseCase> updateUserUseCase, std::shared_ptr<IDeleteUserUseCase> deleteUserUseCase);
	~UserController();
	std::tuple<std::optional<Response<UserOutput>>, std::optional<Response<ErrorResponse>>> create(CreateUserRequest::Body& body);
	std::tuple<std::optional<Response<std::vector<UserOutput>>>, std::optional<Response<ErrorResponse>>> getAll();
	std::tuple<std::optional<Response<UserOutput>>, std::optional<Response<ErrorResponse>>> getById(GetByIdUserRequest::Params& params);
	std::tuple<std::optional<Response<UserOutput>>, std::optional<Response<ErrorResponse>>> update(UpdateUserRequest::Body& body, UpdateUserRequest::Params& params);
	std::tuple<std::optional<Response<std::nullopt_t>>, std::optional<Response<ErrorResponse>>> deleteById(DeleteUserRequest::Params& params);
};