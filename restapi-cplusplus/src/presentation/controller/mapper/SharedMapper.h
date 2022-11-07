#pragma once

#include "vector"
#include "../request/CreateUserRequest.h"
#include <crow.h>
#include "../response/ErrorResponse.h"
#include "../response/Response.h"

class SharedMapper
{
public:
    static crow::json::wvalue toErrorResponseJson(Response<ErrorResponse>& errorResponse) {
		crow::json::wvalue errorJson({
			{"error_type", errorResponse.body.errorType},
			{"error_message", errorResponse.body.errorMessage},
			{"status_code", errorResponse.body.statusCode}
		});
		return errorJson;
    }
};
