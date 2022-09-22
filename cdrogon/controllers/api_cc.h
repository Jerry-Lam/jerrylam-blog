#pragma once
#include <drogon/HttpController.h>
using namespace drogon;
using namespace drogon::orm;

namespace api
{
  class cc : public drogon::HttpController<cc>
  {
  public:
    cc()
    {
      Json::Value temp;
      temp["id"] = 1;
      temp["name"] = "Google";
      data[0] = temp;
    
      auto clientPtr = drogon::app().getDbClient();
      Mapper<drogon_model::testdb::Websites> mp(clientPtr);
      auto f = mp.findOne(
        Criteria(drogon_model::testdb::Websites::Cols::_name, CompareOperator::EQ, "Google")
      );
      temp["google"] = f.toJson();
      data[1] = temp;
    }

  public:
    METHOD_LIST_BEGIN
    // use METHOD_ADD to add your custom processing function here;
    // METHOD_ADD(cc::get, "/{2}/{1}", Get); // path is /api/cc/{arg2}/{arg1}
    // METHOD_ADD(cc::your_method_name, "/{1}/{2}/list", Get); // path is /api/cc/{arg1}/{arg2}/list
    // ADD_METHOD_TO(cc::your_method_name, "/absolute/path/{1}/{2}/list", Get); // path is /absolute/path/{arg1}/{arg2}/list
    METHOD_ADD(cc::list, "/list/{id}", Get);
    METHOD_LIST_END
    // your declaration of processing function maybe like this:
    // void get(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback, int p1, std::string p2);
    void list(const HttpRequestPtr &req,
              std::function<void(const HttpResponsePtr &)> &&callback, int id) const;
    Json::Value data;
  };
}
