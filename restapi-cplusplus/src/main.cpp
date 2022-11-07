#include <iostream>
#include <string>
#include "presentation/Server.h"


int main() {
    Server server;
    server.configRoutes().start(18080);
	return 0;
}