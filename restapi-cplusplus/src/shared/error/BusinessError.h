#pragma once

#include "string"
#include "ErrorBase.h"

class BusinessError : public ErrorBase
{
public:
    BusinessError(std::string errorMessage) : ErrorBase("BUSINESS", 422, errorMessage) {}
    ~BusinessError() {}
};
