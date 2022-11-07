#include "ErrorBase.h"

ErrorBase::ErrorBase(std::string errorType, int statusCode, std::string errorMessage) : runtime_error(errorMessage) {
    this->errorType = errorType;
    this->errorMessage = errorMessage;
    this->statusCode = statusCode;
}

ErrorBase::~ErrorBase() {}

std::string ErrorBase::getErrorType() {
    return this->errorType;
}

std::string ErrorBase::getErrorMessage() {
    return this->errorMessage;
}

int ErrorBase::getStatusCode() {
    return this->statusCode;
}