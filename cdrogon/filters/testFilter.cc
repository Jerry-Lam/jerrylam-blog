/**
 *
 *  testFilter.cc
 *
 */

#include "testFilter.h"
#include <iostream>
#include <jwt/jwt.hpp>

using namespace drogon;

void testFilter::doFilter(const HttpRequestPtr &req,
    FilterCallback &&fcb,
    FilterChainCallback &&fccb)
{
    // Edit your logic here
    // using namespace jwt::params;
    // auto key = "secret";
    // jwt::jwt_object obj{algorithm("HS256"), payload({{"some", "payload"}}), secret(key)};
    // auto enc_str = obj.signature();
    // std::cout << enc_str << std::endl;
    // auto dec_obj = jwt::decode(enc_str, algorithms({"HS256"}), secret(key));
    // std::cout << dec_obj.header() << std::endl;
    // std::cout << dec_obj.payload() << std::endl;

    // std::cout << "testfilter" << std::endl;
    // if (1)
    // {
    //     // Passed
    //     fccb();
    //     return;
    // }
    // // Check failed
    // auto res = drogon::HttpResponse::newHttpResponse();
    // res->setStatusCode(k500InternalServerError);
    // fcb(res);
    // std::cout << req->getHeader("Authorization") << std::endl;
    fccb();
}
