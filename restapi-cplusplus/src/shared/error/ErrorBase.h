#pragma once
#include <string>
#include <stdexcept>

class ErrorBase : public std::runtime_error
{
private:
    std::string errorType;
    std::string errorMessage;
    unsigned int statusCode;
public:
    ErrorBase(std::string errorType, int statusCode, std::string errorMessage);
    ~ErrorBase();
    std::string getErrorType();
    std::string getErrorMessage();
    int getStatusCode();
};
