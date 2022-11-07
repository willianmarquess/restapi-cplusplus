#include "UserController.h"

UserController::UserController(std::shared_ptr<ICreateUserUseCase> createUseCase, std::shared_ptr<IGetAllUsersUseCase> getAllUsersUseCase, std::shared_ptr<IGetUserByIdUseCase> getUserByIdUseCase, std::shared_ptr<IUpdateUserUseCase> updateUserUseCase, std::shared_ptr<IDeleteUserUseCase> deleteUserUseCase)
	: createUseCase(createUseCase), getAllUsersUseCase(getAllUsersUseCase), getUserByIdUseCase(getUserByIdUseCase), updateUserUseCase(updateUserUseCase), deleteUserUseCase(deleteUserUseCase) {}

UserController::~UserController() {}

std::tuple<std::optional<Response<UserOutput>>, std::optional<Response<ErrorResponse>>> UserController::create(CreateUserRequest::Body& body) {
	try
	{
		CreateUserInput createUserInput(body.email, body.password);
		auto createUserOutput = this->createUseCase->execute(createUserInput);
		return { HttpHelper::created(createUserOutput), {}};

	}
	catch (std::exception& e)
	{
		return { {}, HttpHelper::error(e) };
	}
}

std::tuple<std::optional<Response<std::vector<UserOutput>>>, std::optional<Response<ErrorResponse>>> UserController::getAll() {
	try
	{
		auto output = this->getAllUsersUseCase->execute();
		return { HttpHelper::ok(output), {} };
	}
	catch (std::exception& e)
	{
		return { {}, HttpHelper::error(e) };
	}
}

std::tuple<std::optional<Response<UserOutput>>, std::optional<Response<ErrorResponse>>> UserController::getById(GetByIdUserRequest::Params& params) {
	try
	{
		auto output = this->getUserByIdUseCase->execute(params.id);
		return { HttpHelper::ok(output), {} };
	}
	catch (std::exception& e)
	{
		return { {}, HttpHelper::error(e) };
	}
}

std::tuple<std::optional<Response<UserOutput>>, std::optional<Response<ErrorResponse>>> UserController::update(UpdateUserRequest::Body& body, UpdateUserRequest::Params& params) {
	try
	{
		UpdateUserInput updateUserInput(params.id, body.email, body.password);
		auto updateUserOutput = this->updateUserUseCase->execute(updateUserInput);
		return { HttpHelper::created(updateUserOutput), {} };

	}
	catch (std::exception& e)
	{
		return { {}, HttpHelper::error(e) };
	}
}

std::tuple<std::optional<Response<std::nullopt_t>> , std::optional<Response<ErrorResponse>>> UserController::deleteById(DeleteUserRequest::Params& params) {
	try
	{
		this->deleteUserUseCase->execute(params.id);
		return {{},{}};
	}
	catch (std::exception& e)
	{
		return { {}, HttpHelper::error(e) };
	}
}