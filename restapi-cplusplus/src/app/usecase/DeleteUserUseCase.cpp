#include "DeleteUserUseCase.h"

DeleteUserUseCase::DeleteUserUseCase(std::shared_ptr<IUserRepository> repository) : repository(repository) {}

DeleteUserUseCase::~DeleteUserUseCase() {}

void DeleteUserUseCase::execute(std::string id) {
    auto userExists = this->repository->getUserById(id);

    if (!userExists.has_value())
    {
        throw NotFoundError("user not found");
    }

    this->repository->deleteById(id);
}