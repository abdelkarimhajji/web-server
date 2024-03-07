#pragma once

#include "../parse/DataConfig.hpp"
#include "RequestMethods.hpp"
#include "../Server.hpp"
#include "Response.hpp"
#include <map>
#include <algorithm>

class Request {
    private:
        std::string requestEntity;
        std::string requestMethod;
        std::string requestRessource;
        std::string httpVersion;
        std::map<std::string, std::string> headers;
        std::string body;

        std::string path;

        // validation
        int checkAllowedChars(std::string value);
        int validRequest(DataConfig config);

        // parsing
        void parseRequest(std::string buffer, std::string delim);
        void parseRequestLine(std::string buffer);
        void parseHeaders(std::string buffer);
        std::string& trimSpaces(std::string& val);
    public:
        // constructor
        Request(std::string buffer);
        ~Request();

        // getters
        std::string getRequestMethod() const;
        std::string getRequestRessource() const;
        std::string getHttpVersion() const;
        std::string getHeader(std::string key) const;
        std::string getBody() const;
        Response handleRequest(DataConfig config);
        int buildPath(DataConfig config);
        void printHeaders();
};