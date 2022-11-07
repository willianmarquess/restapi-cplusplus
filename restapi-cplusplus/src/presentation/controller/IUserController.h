#pragma once
#pragma once

#include <vector> 
#include <tuple>
#include <optional>
#include "request/CreateUserRequest.h"
#include "response/Response.h"
#include "../../app/output/UserOutput.h"
#include "response/ErrorResponse.h"
#include "request/UpdateUserRequest.h"
#include "request/GetByIdUserRequest.h"
#include "request/DeleteUserRequest.h"

class IUserController
{
public:
	virtual std::tuple<std::optional<Response<UserOutput>>, std::optional<Response<ErrorResponse>>> create(CreateUserRequest::Body& body) = 0;
	virtual std::tuple<std::optional<Response<std::vector<UserOutput>>>, std::optional<Response<ErrorResponse>>>  getAll() = 0;
	virtual std::tuple<std::optional<Response<UserOutput>>, std::optional<Response<ErrorResponse>>> getById(GetByIdUserRequest::Params& params) = 0;
	virtual std::tuple<std::optional<Response<UserOutput>>, std::optional<Response<ErrorResponse>>> update(UpdateUserRequest::Body& body, UpdateUserRequest::Params& params) = 0;
	virtual std::tuple<std::optional<Response<std::nullopt_t>>, std::optional<Response<ErrorResponse>>> deleteById(DeleteUserRequest::Params& params) = 0;
};