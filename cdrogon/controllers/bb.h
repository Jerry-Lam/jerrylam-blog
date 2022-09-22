#pragma once

#include <drogon/HttpSimpleController.h>

using namespace drogon;

class bb : public drogon::HttpSimpleController<bb>
{
  public:
    void asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback) override;
    PATH_LIST_BEGIN
    // list path definitions here;
    PATH_ADD("/bb", Get);
    PATH_LIST_END
};
