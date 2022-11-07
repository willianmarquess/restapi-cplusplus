#include "CreateUserUseCase.h"

CreateUserUseCase::CreateUserUseCase(std::shared_ptr<IUserRepository> repository) : repository(repository) {}

CreateUserUseCase::~CreateUserUseCase() {}

UserOutput CreateUserUseCase::execute(CreateUserInput& createUserInput) {
    auto user = UserMapper::createUserInputToUser(createUserInput);
    auto& userCreated = this->repository->create(user);
    auto output = UserMapper::userToUserOutput(userCreated);
    return output;
}
