#pragma once

#include <iostream>

class Http {
public:
    virtual ~Http(){}
    virtual void initialize() = 0;
    virtual std::string get(const std::string& url) const = 0;
};

class PlaceDescriptionService {
public:
    PlaceDescriptionService(Http* http) : _http{ http }
    {}
    std::string description() const {
        std::string server = "https://someserver.com/";
        std::string doc = "api/test_json";
        auto getRequestUrl = server + doc;
        auto jsonResponse = _http->get(getRequestUrl);

        /* Service we want to test extracts the road name and returns normal string data */
        // return Service.extract_roadname(jsonResponse)

        return "123 Fake St";
    }
protected:
    Http *_http;
};