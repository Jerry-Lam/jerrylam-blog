/**
 *
 *  testddFilter.cc
 *
 */

#include "testddFilter.h"
#include "jwt/jwt.hpp"
#include <nlohmann/json.hpp>
#include "../models/Testuser.h"

using namespace jwt::params;
using namespace drogon::orm;

class User
{
public:
    std::string username;
    int id = 0;

public:
    User(nlohmann::json);
    ~User();
};

User::User(nlohmann::json data)
{

    if (!data.empty())
    {
        if (!data["username"].empty())
            username = data["username"];

        if (!data["id"].empty())
        {
            std::string dataId = data["id"];
            id = atoi(dataId.c_str());
        }
    }
}

User::~User()
{
}

void testddFilter::doFilter(const HttpRequestPtr &req,
                            FilterCallback &&fcb,
                            FilterChainCallback &&fccb)
{
    // Edit your logic here
    Json::Value json;
    auto clientPtr = drogon::app().getDbClient();
    Mapper<drogon_model::testdb::Testuser> mp(clientPtr);
    if (req->getHeader("Authorization").empty())
        json["error"] = "请提供token";
        // json["error"] = "JWT must be provided";

    if (!req->getHeader("Authorization").empty())
    {
        std::string Authorization = req->getHeader("Authorization");
        std::string token;
        std::string Bearer = "Bearer ";
        if (Authorization.find(Bearer) == std::string::npos)
            json["error"] = "token错误";
        else
        // Authorization不为空，验证token
        {
            std::error_code ec;
            std::size_t cut = Authorization.find(Bearer);
            token = Authorization.substr(cut + Bearer.length());
            auto dec = jwt::decode(token, algorithms({"HS256"}), ec, secret("secret"), verify(true));
            if (ec.value() == static_cast<int>(jwt::VerificationErrc::TokenExpired))
            {
                json["error"] = "token已过期或无效";
            }
            else
            {
                User user(dec.payload().create_json_obj());
                if (user.username.empty())
                    json["error"] = "token错误";

                if (user.id == 0)
                    json["error"] = "token错误";

                if (!user.username.empty() && user.id)
                {
                    //解密后，查询数据库是否真的有这个用户
                    drogon_model::testdb::Testuser data;
                    try
                    {
                        data = mp.findOne(Criteria(drogon_model::testdb::Testuser::Cols::_username, CompareOperator::EQ, user.username));
                    }
                    catch(const DrogonDbException& e)
                    {
                        json["error"] = "用户不存在";
                    }

                    if (json.empty())
                    {
                        if (user.id == data.getValueOfId())
                        {
                            json["error"] = "token错误";
                        }
                    }
                    
                    
                }
            }

            // nlohmann::json dec_Json;
            // dec_Json = dec.payload().create_json_obj();
            //用一个类user,用username和id来约束，查询数据库里的username和id对不对的上

            // call dump()
            // std::cout << "objects:" << '\n'
            //           << dec.payload().create_json_obj().dump() << std::endl;

            //   << dec.payload().create_json_obj().dump(-1) << "\n\n"
            //   << dec.payload().create_json_obj().dump(0) << "\n\n"
            //   << dec.payload().create_json_obj().dump(4) << "\n\n"
            //   << dec.payload().create_json_obj().dump(1, '\t') << "\n\n";

            // std::cout << ec << std::endl;
            // std::cout << ec.value() << std::endl;
            // std::cout << (ec.value() == static_cast<int>(jwt::VerificationErrc::TokenExpired)) << std::endl;
        }
    }

    if (json.empty())
    {
        //错误是否为空，为空继续执行，不为空返回错误
        fccb();
        return;
    }

    // Check failed

    // auto res = drogon::HttpResponse::newHttpResponse();
    // res->setStatusCode(k500InternalServerError);
    // fcb(res);
    auto res = HttpResponse::newHttpJsonResponse(json);
    // res->setStatusCode(k500InternalServerError);
    fcb(res);
}
