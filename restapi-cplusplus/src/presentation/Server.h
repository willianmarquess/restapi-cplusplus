#pragma once

#include <crow.h>
#include "factory/UserControllerFactory.h"
#include "controller/request/CreateUserRequest.h"
#include "controller/mapper/UserPresentationMapper.h"

class Server
{
public:
	Server();
	~Server();
	Server& configRoutes();
	void start(const int PORT);
private:
	crow::SimpleApp app;
};
