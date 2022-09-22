#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace api
{
  class dd : public drogon::HttpController<dd>
  {
  public:
    METHOD_LIST_BEGIN
    // ADD_METHOD_TO(dd::getData, "/dd", Post,"testFilter");
    ADD_METHOD_TO(dd::getData, "/dd", Post, "testddFilter");

    METHOD_LIST_END
    void getData(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, Json::Value data) const;
  };
}

namespace drogon
{
  template <>
  inline Json::Value fromRequest(const HttpRequest &req)
  {
    return *req.getJsonObject();
  }
}

// namespace drogon
// {
//   template <>
//   inline Json::Value fromRequest(const HttpRequest &req)
//   {
//     Json::Value data;
//     auto json = req.getJsonObject();
//     if (json)
//     {
//       std::cout << json.get()->toStyledString() << std::endl;
//       // data = (*json).asString();
//     }
//     else
//     {
//       std::cout << "not json" << std::endl;
//     }

//     return data;
//   }
// }