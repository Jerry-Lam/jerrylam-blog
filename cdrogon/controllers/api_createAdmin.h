#pragma once

#include <drogon/HttpController.h>

using namespace drogon;

namespace admin
{
  struct User
  {
    std::string username;
    std::string password;
  };
}

namespace drogon
{
  template <>
  inline admin::User fromRequest(const HttpRequest &req)
  {
    auto json = req.getJsonObject();
    admin::User user;
    if (json)
    {
      user.username = (*json)["username"].asString();
      user.password = (*json)["password"].asString();
    }
    return user;
  }
}

namespace api
{
  class createAdmin : public drogon::HttpController<createAdmin>
  {
  public:
    METHOD_LIST_BEGIN
    ADD_METHOD_TO(createAdmin::createAdminUser, "/createadmin", Post);

    METHOD_LIST_END
    void createAdminUser(const HttpRequestPtr &req, std::function<void(const HttpResponsePtr &)> &&callback, admin::User &&data) const;
  };
}
