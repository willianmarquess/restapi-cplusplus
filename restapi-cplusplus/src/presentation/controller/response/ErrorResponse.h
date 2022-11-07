#pragma once

#include <string>

class ErrorResponse
{
public:
	ErrorResponse(){}
	~ErrorResponse() {}
	unsigned int statusCode = 200;
	std::string errorType;
	std::string errorMessage;
};