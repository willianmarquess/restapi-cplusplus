#pragma once

#include "vector"
#include "../../domain/entity/User.h"
#include "../output/UserOutput.h"
#include "../input/CreateUserInput.h"
#include "../input/UpdateUserInput.h"

class UserMapper
{
public:
    static User createUserInputToUser(CreateUserInput& input) {
        User user({}, input.email, input.password);
        return user;
    }

    static UserOutput userToUserOutput(User& user) {
        UserOutput output(user.getId(), user.getEmail(), user.getPassword());
        return output;
    }

    static std::vector<UserOutput> userListToUserOutputList(std::vector<User>& users) {
        std::vector<UserOutput> output{};
        for (auto& user : users)
        {
            output.push_back(userToUserOutput(user));
        }
        return output;
    }

    static User updateUserInputToUser(UpdateUserInput& input) {
        User user(input.id, input.email, input.password);
        return user;
    }
};
