#pragma once

#include "../response/Response.h"
#include "../response/ErrorResponse.h"
#include "../../../shared/util/InstanceOf.h"
#include "../../../shared/error/NotFoundError.h"

class HttpHelper
{
public:
	template<class T>
	static Response<T> ok(T& output) {
		Response<T> response(output, 200);
		return response;
	}

	template<class T>
	static Response<T> created(T& output) {
		Response<T> response(output, 201);
		return response;
	}

	template<class T>
	static Response<T> noContent(T& output) {
		Response<T> response(output, 204);
		return response;
	}

	static Response<ErrorResponse> error(std::exception& e) {
		ErrorResponse errorResponse;
		Response<ErrorResponse> response;
		if (instanceof<ErrorBase>(&e)) {
			auto errorApp = dynamic_cast<ErrorBase*>(&e);
			errorResponse.statusCode = errorApp->getStatusCode();
			errorResponse.errorMessage = errorApp->getErrorMessage();
			errorResponse.errorType = errorApp->getErrorType();
			response.body = errorResponse;
			response.statusCode = errorResponse.statusCode;
			return response;
		}

		errorResponse.errorType = "SERVER_ERROR";
		errorResponse.errorMessage = "server error";
		errorResponse.statusCode = 500;
		response.body = errorResponse;
		response.statusCode = errorResponse.statusCode;
		return response;
	}
};
