#pragma once

#include "../Server.hpp"
#include <map>
#include <sstream>
#include <vector>
#include <algorithm>

class Response {
    private:
        std::string httpVersion;
        unsigned int code;
        std::string status;
        std::string contentType;
        unsigned int contentLength;
        std::map<std::string, std::string> headers;
        std::string body;
        std::string responseEntity;

    public:
        Response();
        void buildResponse(unsigned int code);
        void sendResponse(int socket);

        Response(const Response& ref);
        Response& operator=(const Response& ref);

        void setStatus(unsigned int code);
        void setContentType(std::string fileExtension);
        void setContentLength(unsigned int length);
        void setResponseBody(std::string content);
        void setHeader(std::string key, std::string value);

        std::string getResponseEntity();
};