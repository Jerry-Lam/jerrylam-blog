#include "api_createAdmin.h"
#include "../models/Testuser.h"
// #include "3rdparty/bcrypt/include/bcrypt.h"
#include "bcrypt/BCrypt.hpp"

using namespace api;
using namespace drogon::orm;

// Add definition of your processing function here
void createAdmin::createAdminUser(const HttpRequestPtr &req,
                                  std::function<void(const HttpResponsePtr &)> &&callback,
                                  admin::User &&data) const
{
    Json::Value value;
    drogon::HttpResponsePtr resp;

    auto clientPtr = drogon::app().getDbClient();
    Mapper<drogon_model::testdb::Testuser> mp(clientPtr);
    drogon_model::testdb::Testuser user;

    if (data.username.empty())
        value["error"] = "username没有传参";

    if (data.password.empty())
        value["error"] = "password没有传参";

    if (data.username.empty() && data.password.empty())
        value["error"] = "必须传参";

    if (!data.username.empty() && !data.password.empty())
    {
        auto json = std::make_shared<Json::Value>(std::move(value));
        auto callbackPtr =
            std::make_shared<std::function<void(const HttpResponsePtr &)>>(
                std::move(callback));

        auto successFuntion = [&json, callbackPtr](const drogon_model::testdb::Testuser &v)
        {
            (*json)["message"] = "注册成功";
            auto resp = HttpResponse::newHttpJsonResponse(*json);
            (*callbackPtr)(resp);
        };

        auto errorFuntion = [&json, callbackPtr](const DrogonDbException &e)
        {
            (*json)["error"] = "注册失败";
            LOG_ERROR << "error:" << e.base().what();
            auto resp = HttpResponse::newHttpJsonResponse(*json);
            (*callbackPtr)(resp);
        };
        user.setUsername(data.username);
        user.setPassword(BCrypt::generateHash(data.password, 12));
        mp.insert(user, successFuntion, errorFuntion);
    }

    if (!value.empty())
    {
        resp = HttpResponse::newHttpJsonResponse(value);
        callback(resp);
    }
}