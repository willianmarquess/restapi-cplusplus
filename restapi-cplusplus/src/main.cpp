#include <iostream>
#include <string>
#include "presentation/Server.h"


int main() {
    Server server;
    server.configRoutes().start(3333);
	return 0;
}