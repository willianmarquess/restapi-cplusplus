#include "UpdateUserUseCase.h"
#include "../../shared/error/NotFoundError.h"

UpdateUserUseCase::UpdateUserUseCase(std::shared_ptr<IUserRepository> repository) : repository(repository) {}

UpdateUserUseCase::~UpdateUserUseCase() {}

UserOutput UpdateUserUseCase::execute(UpdateUserInput& updateUserInput) {

    auto userExists = this->repository->getUserById(updateUserInput.id);
    if (!userExists.has_value()) {
        throw NotFoundError("user not found");
    }

    auto user = UserMapper::updateUserInputToUser(updateUserInput);
    auto& userUpdated = this->repository->update(user);
    auto output = UserMapper::userToUserOutput(userUpdated);
    return output;
}
