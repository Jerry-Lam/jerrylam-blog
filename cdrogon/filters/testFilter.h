/**
 *
 *  testFilter.h
 *
 */

#pragma once

#include <drogon/HttpFilter.h>
using namespace drogon;

class testFilter : public HttpFilter<testFilter>
{
public:
  testFilter() {}
  void doFilter(const HttpRequestPtr &req,
                FilterCallback &&fcb,
                FilterChainCallback &&fccb) override;
};
