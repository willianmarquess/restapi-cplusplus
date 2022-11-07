#include "Server.h"
#include "controller/mapper/SharedMapper.h"

Server::Server() {}

Server::~Server() {}

Server& Server::configRoutes() {

	CROW_ROUTE(this->app, "/check")([]() {
		return "i'm alive!!!";
	});

	CROW_ROUTE(this->app, "/api/user")
		.methods("POST"_method)([](const crow::request& req){

		auto userController = UserControllerFactory::create();

		auto userJson = crow::json::load(req.body);
		auto body = UserPresentationMapper::userJsonToCreateUserBody(userJson);

		auto [response, error] = userController->create(body);

		if (response.has_value()) {
			auto& userResponse = response.value();
			auto userJson = UserPresentationMapper::userResponseToUserResponseJson(userResponse);
			return crow::response(userResponse.statusCode, userJson);
		}

		auto& errorResponse = error.value();
		auto errorResponseJson = SharedMapper::toErrorResponseJson(errorResponse);
		return crow::response(errorResponse.statusCode, errorResponseJson);

	});

	CROW_ROUTE(this->app, "/api/user")
		.methods("GET"_method)([](const crow::request& req) {

		auto userController = UserControllerFactory::create();

		auto [response, error] = userController->getAll();

		if (response.has_value()) {
			auto& usersResponse = response.value();
			auto usersResponseJson = UserPresentationMapper::usersResponseToUsersResponseJson(usersResponse);
			return crow::response(usersResponse.statusCode, usersResponseJson);
		}

		auto& errorResponse = error.value();
		auto errorResponseJson = SharedMapper::toErrorResponseJson(errorResponse);
		return crow::response(errorResponse.statusCode, errorResponseJson);

	});

	CROW_ROUTE(this->app, "/api/user/<string>")
		.methods("GET"_method)([](const crow::request& req, std::string id) {

		auto userController = UserControllerFactory::create();

		GetByIdUserRequest::Params params{ id };

		auto [response, error] = userController->getById(params);

		if (response.has_value()) {
			auto& userResponse = response.value();
			auto userJson = UserPresentationMapper::userResponseToUserResponseJson(userResponse);
			return crow::response(userResponse.statusCode, userJson);
		}

		auto& errorResponse = error.value();
		auto errorResponseJson = SharedMapper::toErrorResponseJson(errorResponse);
		return crow::response(errorResponse.statusCode, errorResponseJson);

	});

	CROW_ROUTE(this->app, "/api/user/<string>")
		.methods("PUT"_method)([](const crow::request& req, std::string id) {

		auto userController = UserControllerFactory::create();

		auto userJson = crow::json::load(req.body);
		auto body = UserPresentationMapper::userJsonToUpdateUserBody(userJson);
		UpdateUserRequest::Params params{ id };

		auto [response, error] = userController->update(body, params);

		if (response.has_value()) {
			auto& userResponse = response.value();
			auto userJson = UserPresentationMapper::userResponseToUserResponseJson(userResponse);
			return crow::response(userResponse.statusCode, userJson);
		}

		auto& errorResponse = error.value();
		auto errorResponseJson = SharedMapper::toErrorResponseJson(errorResponse);
		return crow::response(errorResponse.statusCode, errorResponseJson);

	});

	CROW_ROUTE(this->app, "/api/user/<string>")
		.methods("DELETE"_method)([](const crow::request& req, std::string id) {

		auto userController = UserControllerFactory::create();

		DeleteUserRequest::Params params{ id };

		auto [_, error] = userController->deleteById(params);

		if (error.has_value()) {
			auto& errorResponse = error.value();
			auto errorResponseJson = SharedMapper::toErrorResponseJson(errorResponse);
			return crow::response(errorResponse.statusCode, errorResponseJson);
		}
		return crow::response(204);
	});

	return *this;
}

void Server::start(const int PORT = 3333) {
	this->app.port(PORT).multithreaded().run();
}