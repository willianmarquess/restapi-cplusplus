#include "GetAllUsersUseCase.h"

GetAllUsersUseCase::GetAllUsersUseCase(std::shared_ptr<IUserRepository> repository) : repository(repository) {}

GetAllUsersUseCase::~GetAllUsersUseCase() {}

std::vector<UserOutput> GetAllUsersUseCase::execute() {
    auto users = this->repository->getUsers();
    auto output = UserMapper::userListToUserOutputList(users);
    return output;
}