#include "../models/Websites.h"
#include "api_dd.h"
// #include "jsoncpp/json/json.h"

using namespace api;
// using namespace drogon;
using namespace drogon::orm;
void print_json(const Json::Value &value, bool emitUTF8);
// Add definition of your processing function here
void dd::getData(const HttpRequestPtr &req,
                 std::function<void(const HttpResponsePtr &)> &&callback,
                 Json::Value data) const
{
    // if (data)
    // {
    //     std::cout << 456 << std::endl;
    //     std::cout << data << std::endl;
    // }

    // auto resp = HttpResponse::newHttpJsonResponse(data);
    // callback(resp);
    // std::cout << req.get()->getJsonObject().get()->toStyledString() << std::endl;
    // auto json = req.get()->getJsonObject();
    // std::cout << (*json)["id"].asString() << std::endl;

    auto clientPtr = drogon::app().getDbClient();
    Mapper<drogon_model::testdb::Websites> mp(clientPtr);
    // auto f = mp.findBy(Criteria(drogon_model::testdb::Websites::Cols::_name, CompareOperator::EQ, data));
    // std::cout << f.data() << " rows selected!" << std::endl;
    Json::Value json;
    // mp.limit(1).offset(1).findAll
    auto callbackPtr =
        std::make_shared<std::function<void(const HttpResponsePtr &)>>(
            std::move(callback));

    mp.findAll(
        [clientPtr, &json, callbackPtr](const std::vector<drogon_model::testdb::Websites> &v)
        {
            Mapper<drogon_model::testdb::Websites> up(clientPtr);
            // std::cout << v.size() << std::endl;
            // std::cout << v.data()->getValueOfName() << " rows selected!" << std::endl;

            for (auto i : v)
            {
                (json)["data"].append(i.getValueOfName());
            }

            auto resp = HttpResponse::newHttpJsonResponse(json);
            (*callbackPtr)(resp);

            // for (auto g : v)
            // {
            //     g.setName("天猫");
            //     up.update(
            //         g,
            //         [](const size_t count)
            //         {
            //             LOG_DEBUG << "update " << count << " rows";
            //         },
            //         [](const DrogonDbException &e)
            //         {
            //             LOG_ERROR << e.base().what();
            //         });
            // }
        },
        [](const DrogonDbException &e)
        { LOG_ERROR << e.base().what(); });
    // std::cout << result.size() << " rows selected!" << std::endl;

    // Json::StreamWriterBuilder builder;
    // builder.settings_["emitUTF8"] = true;
    // std::cout << data << std::endl;
    // print_json(data, true);
    // auto resp = HttpResponse::newHttpJsonResponse(json);
    // callback(resp);
}

// namespace drogon
// {
//     template <>
//     inline Json::Value fromRequest(const HttpRequest &req)
//     {
//         return *req.getJsonObject();
//     }
// }

void print_json(const Json::Value &value, bool emitUTF8)
{
    Json::StreamWriterBuilder builder;
    builder.settings_["emitUTF8"] = emitUTF8;
    std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
    writer->write(value, &std::cout);
}