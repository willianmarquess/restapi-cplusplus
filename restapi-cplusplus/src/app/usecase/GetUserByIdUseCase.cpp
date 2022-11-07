#include "GetUserByIdUseCase.h"

GetUserByIdUseCase::GetUserByIdUseCase(std::shared_ptr<IUserRepository> repository) : repository(repository) {}

GetUserByIdUseCase::~GetUserByIdUseCase() {}

UserOutput GetUserByIdUseCase::execute(std::string id) {
    auto userExists = this->repository->getUserById(id);

    if (!userExists.has_value())
    {
        throw NotFoundError("user not found");
    }

    auto output = UserMapper::userToUserOutput(userExists.value());
    return output;
}