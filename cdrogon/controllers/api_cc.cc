#include "../models/Websites.h"
#include "api_cc.h"

using namespace api;

// Add definition of your processing function here
void cc::list(const HttpRequestPtr &req,
              std::function<void(const HttpResponsePtr &)> &&callback, int id) const
{
    Json::Value json;
    json["code"] = 0;
    json["message"] = "get message success";

    Json::Value data;
    data["id"] = 1;
    data["name"] = "Google";
    json["date"][0] = data;
    
    auto clientPtr = drogon::app().getDbClient();
    Mapper<drogon_model::testdb::Websites> mp(clientPtr);
    auto f = mp.findOne(Criteria(drogon_model::testdb::Websites::Cols::_name, CompareOperator::EQ, "Google"));
    // std::cout << f.toJson() << std::endl;
    data["google"] = f.toJson();
    json["date"][1] = data;
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}