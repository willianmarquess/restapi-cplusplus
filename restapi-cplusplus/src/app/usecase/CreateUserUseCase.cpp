#include "CreateUserUseCase.h"
#include "../../shared/error/BusinessError.h"

CreateUserUseCase::CreateUserUseCase(std::shared_ptr<IUserRepository> repository) : repository(repository) {}

CreateUserUseCase::~CreateUserUseCase() {}

UserOutput CreateUserUseCase::execute(CreateUserInput& createUserInput) {
    auto userExists = this->repository->getByEmail(createUserInput.email);

    if (userExists.has_value()) {
        throw BusinessError("email already exists");
    }

    auto user = UserMapper::createUserInputToUser(createUserInput);
    auto& userCreated = this->repository->create(user);
    auto output = UserMapper::userToUserOutput(userCreated);
    return output;
}
