#include "bb.h"

void bb::asyncHandleHttpRequest(const HttpRequestPtr& req, std::function<void (const HttpResponsePtr &)> &&callback)
{
    Json::Value data;
    data["code"] = 0;
    data["message"] = "成功";
    auto resp = HttpResponse::newHttpJsonResponse(data);
    callback(resp);
}
