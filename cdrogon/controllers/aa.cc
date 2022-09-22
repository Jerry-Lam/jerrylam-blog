#include "aa.h"
#include "../models/Websites.h"
using namespace drogon::orm;

void aa::asyncHandleHttpRequest(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback)
{
    
    // resp->setStatusCode(k200OK);
    // resp->setContentTypeCode(CT_TEXT_HTML);
    // resp->setBody("DROGON");

    // auto clientPtr = drogon::app().getDbClient();
    // auto f = clientPtr->execSqlAsyncFuture("select * from websites");
    // auto result = f.get();
    // std::cout << result.size() << " rows selected!" << std::endl;
    // int i = 0;
    // for (auto row : result)
    // {
    //     std::cout << i++ << ":  name is " << row["name"].as<std::string>() << std::endl;
    // }
    auto clientPtr = drogon::app().getDbClient();
    Mapper<drogon_model::testdb::Websites> mp(clientPtr);
    auto result = mp.findAll();
    std::cout << result.size() << " rows selected!" << std::endl;
    mp.findAll(
        [](const std::vector<drogon_model::testdb::Websites> &v)
        {
            std::cout << v.size() << " rows selected!" << std::endl;
            for (auto g : v)
            {
                std::cout << "name:" << g.getValueOfName();
                // std::cout << g.toJson() << std::endl;
            }
        },
        [](const DrogonDbException &e)
        { LOG_ERROR << e.base().what(); });
    auto f = mp.findOne(Criteria(drogon_model::testdb::Websites::Cols::_name, CompareOperator::EQ, "天猫"));
    std::cout << f.toJson() << std::endl;
    auto resp = HttpResponse::newHttpJsonResponse(f.toJson());
    callback(resp);
}
