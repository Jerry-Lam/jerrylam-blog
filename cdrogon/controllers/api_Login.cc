#include "api_Login.h"
#include "../models/Testuser.h"
// #include "3rdparty/bcrypt/include/bcrypt.h"
#include "bcrypt/BCrypt.hpp"
#include "jwt/jwt.hpp"

using namespace api;
using namespace drogon::orm;

void Login::login(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, admin::User &&data) const
{
    //同步处理
    // Json::Value json;
    // auto clientPtr = drogon::app().getDbClient();

    // try
    // {
    //     Mapper<drogon_model::testdb::Testuser> mp(clientPtr);
    //     auto user = mp.findOne(Criteria(drogon_model::testdb::Testuser::Cols::_username, CompareOperator::EQ, data.username));
    //     json["password"] = *user.getPassword();
    // }
    // catch(const DrogonDbException& e)
    // {
    //     json["error"] = e.base().what();
    //     std::cout << "error:" << e.base().what() << std::endl;
    // }

    // auto resp = HttpResponse::newHttpJsonResponse(json);
    // callback(resp);

    //异步处理
    // Json::Value value;
    // auto json = std::make_shared<Json::Value>(std::move(value));
    // auto callbackPtr =
    //     std::make_shared<std::function<void(const HttpResponsePtr &)>>(
    //         std::move(callback));

    // auto clientPtr = drogon::app().getDbClient();
    // Mapper<drogon_model::testdb::Testuser> mp(clientPtr);

    // auto successFuntion = [&json, callbackPtr, data](const drogon_model::testdb::Testuser &v)
    // {
    //     auto req = bcrypt::validatePassword(data.password, *v.getPassword());
    //     if (req)
    //     {
    //         (*json)["message"] = "登陆成功";
    //     }
    //     else
    //     {
    //         (*json)["message"] = "密码不正确";
    //     }

    //     auto resp = HttpResponse::newHttpJsonResponse(*json);
    //     (*callbackPtr)(resp);
    // };

    // auto errorFuntion = [&json, callbackPtr](const DrogonDbException &e)
    // {
    //     (*json)["message"] = "用户不存在";
    //     LOG_ERROR << "error:" << e.base().what();
    //     auto resp = HttpResponse::newHttpJsonResponse(*json);
    //     (*callbackPtr)(resp);
    // };
    // mp.findOne(
    //     Criteria(drogon_model::testdb::Testuser::Cols::_username, CompareOperator::EQ, data.username),
    //     successFuntion,
    //     errorFuntion);

    Json::Value value;
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

        auto clientPtr = drogon::app().getDbClient();
        Mapper<drogon_model::testdb::Testuser> mp(clientPtr);

        auto successFuntion = [&json, callbackPtr, data](const drogon_model::testdb::Testuser &v)
        {
            auto req = BCrypt::validatePassword(data.password, *v.getPassword());
            if (req)
            {
                using namespace jwt::params;
                Json::Value Payload;
                Payload["id"] = *v.getId();
                Payload["username"] = *v.getUsername();
                auto key = "secret"; //加密的key,值可以是任何加密的东西，后面拿来验证
                jwt::jwt_object obj{algorithm("HS256"), payload({{"id", Payload["id"].asString()}, {"username", Payload["username"].asString()}}), secret(key)};
                obj.add_claim("iat", std::chrono::system_clock::now())
                    .add_claim("exp", std::chrono::system_clock::now() + std::chrono::seconds{30});

                auto enc_str = obj.signature();
                (*json)["token"] = enc_str;
            }
            else
            {
                (*json)["message"] = "密码不正确";
            }

            auto resp = HttpResponse::newHttpJsonResponse(*json);
            (*callbackPtr)(resp);
        };

        auto errorFuntion = [&json, callbackPtr](const DrogonDbException &e)
        {
            (*json)["message"] = "用户不存在";
            LOG_ERROR << "error:" << e.base().what();
            auto resp = HttpResponse::newHttpJsonResponse(*json);
            (*callbackPtr)(resp);
        };
        
        mp.findOne(
            Criteria(drogon_model::testdb::Testuser::Cols::_username, CompareOperator::EQ, data.username),
            successFuntion,
            errorFuntion);
    }
    else
    {
        auto resp = HttpResponse::newHttpJsonResponse(value);
        callback(resp);
    }
}
