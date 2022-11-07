#pragma once

#include "string"
#include "ErrorBase.h"

class NotFoundError : public ErrorBase
{
public:
    NotFoundError(std::string errorMessage) : ErrorBase("NOT_FOUND", 404, errorMessage) {}
    ~NotFoundError() {}
};
