/**
 *
 *  testddFilter.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>
#include <drogon/HttpController.h>

using namespace drogon;


class testddFilter : public HttpFilter<testddFilter>
{
  public:
    testddFilter() {}
    void doFilter(const HttpRequestPtr &req,
                  FilterCallback &&fcb,
                  FilterChainCallback &&fccb) override;
};

