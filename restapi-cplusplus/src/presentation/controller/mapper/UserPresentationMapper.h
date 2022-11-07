#pragma once

#include "vector"
#include "../request/CreateUserRequest.h"
#include "../request/UpdateUserRequest.h"
#include <crow.h>

class UserPresentationMapper
{
public:
    static CreateUserRequest::Body userJsonToCreateUserBody(crow::json::rvalue& userJson) {
        CreateUserRequest::Body body;
        body.email = userJson["email"].s();
        body.password = userJson["password"].s();
        return body;
    }

    static crow::json::wvalue userResponseToUserResponseJson(Response<UserOutput>& userResponse) {
        crow::json::wvalue userJson({
            {"id", userResponse.body.id},
            {"email", userResponse.body.email},
            {"password", userResponse.body.password}
         });
        return userJson;
    }

    static crow::json::wvalue usersResponseToUsersResponseJson(Response<std::vector<UserOutput>>& usersResponse) {
        std::vector<crow::json::wvalue> usersJson;
        for (auto& user : usersResponse.body)
        {
            crow::json::wvalue userJson({
                {"id", user.id},
                {"email", user.email},
                {"password", user.password}
             });
            usersJson.emplace_back(userJson);
        }
        return usersJson;
    }

    static UpdateUserRequest::Body userJsonToUpdateUserBody(crow::json::rvalue& userJson) {
        UpdateUserRequest::Body body;
        body.email = userJson["email"].s();
        body.password = userJson["password"].s();
        return body;
    }
};
