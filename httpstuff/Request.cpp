#include "Request.hpp"
#include "RequestMethods.hpp"
#include <string>
#include <vector>

//  ******** PARSING METHODS ********

std::string& Request::trimSpaces(std::string& val) {
    std::string whiteSpaces = "\t ";
    val.erase(val.find_last_not_of(whiteSpaces) + 1);
    val.erase(0, val.find_first_not_of(whiteSpaces));
    return (val);
}

void Request::parseRequestLine(std::string buffer) {
    std::stringstream requestLine(buffer);
    std::vector<std::string> tokens;
    std::string token;

    while (std::getline(requestLine, token, ' ')) {
        tokens.push_back(token);
    }
    this->requestMethod = trimSpaces(tokens[0]);
    this->requestRessource = trimSpaces(tokens[1]);
    this->httpVersion = trimSpaces(tokens[2]);
}

void Request::parseHeaders(std::string buffer) {
    std::stringstream requestLine(buffer);
    std::string key;
    std::string value;

    std::getline(requestLine, key, ':');
    std::getline(requestLine, value, ':');
    this->headers[trimSpaces(key)] = trimSpaces(value);
}

void Request::parseRequest(std::string buffer, std::string delim) {
    std::vector<std::string> values;
    std::string line;
    size_t pos = 0;

    while ((pos = buffer.find(delim))!= std::string::npos) {
        if (buffer.compare(0, 4, delim, 0, 4) == 0) {
            values.push_back(delim);
        }
        line = buffer.substr(0, pos);
        values.push_back(line);
        buffer.erase(0, pos + delim.size());
    }
    if (!buffer.empty()) {
        body = buffer;
    }
    for (size_t i = 0; i < values.size() && values[i].compare(delim) != 0; i++) {
        if (i == 0) {
            parseRequestLine(values[i]);
        } else {
            parseHeaders(values[i]);
        }
    }
}

int Request::validRequest(DataConfig config) {
    if (headers.find("Transfer-Encoding") != headers.end()) {
        std::cout << "transfer encoding found\n";
        if (headers["Transfer-Encoding"] != "chunked") {
             std::cout << " \n";
            return (501);
        }
    }
    // if (requestMethod == "POST" && ( headers.find("Content-Length") == headers.end() || headers.find("Transfer-Encoding") == headers.end())) {
        
    //     return (BAD_REQUEST);
    // }
    if (requestMethod == "POST" && (headers.find("Content-Length") == headers.end())) {
        return (BAD_REQUEST);
    }
    if (checkAllowedChars(requestRessource) == 400) {
        std::cout << "request uri : Bad request\n";
        return (BAD_REQUEST);
    }
    if (requestRessource.size() > 2048)
    {
        std::cout << "request uri : exceeded 2048\n";
        return (REQUEST_URI_EXCEEDED);
    }
    // if client request body is larger than maximum body allowed in config file (change 8000 value to config file value
    if (requestEntity.size() > 8000) {
        std::cout << "request entity too large\n";
        return (ENTITY_LENGTH_EXCEEDED);
    }
    std::vector<Location> locations = config.getLocation();
    if (requestRessource[requestRessource.size() - 1] != '/') {
        std::string requestedRessource = requestRessource.substr(1);
        for (std::vector<Location>::iterator it = locations.begin(); it != locations.end(); it++) {
            if (it->location.substr(1, it->location.size() - 2).compare(requestedRessource) == 0) {
                return (301);
            }
        }
    }
    return (0);
}

int Request::checkAllowedChars(std::string value) {
    std::string allowedChars = "-._~:/?#[]@!$&&\'()*+;=%}";
    for (size_t i = 0; i < value.size(); i++) {
        if (!std::isalpha(value[i]) && !std::isdigit(value[i]) && allowedChars.find(value[i]) == std::string::npos) {
            // change the hardcoded value into a macro
            return (400);
        }
    }
    return (0);
}

//  ******** CONSTRUCTORS ********

Request::Request(std::string buffer) {
    requestEntity = buffer;
    parseRequest(buffer, "\r\n");
    path = "";    
}

Request::~Request() {

}

//  ******** GETTERS ********

std::string Request::getRequestMethod() const {
    return (this->requestMethod);
}

std::string Request::getRequestRessource() const {
    return (this->requestRessource);
}

std::string Request::getHttpVersion() const {
    return (this->httpVersion);
}

std::string Request::getHeader(std::string key) const {
    std::map<std::string, std::string>::const_iterator it = headers.find(key);
    if (it != headers.end())
        return (it->second);
    else
        return "";
}

std::string Request::getBody() const {
    return (this->body);
}

void    Request::printHeaders() {
    for (std::map<std::string, std::string>::iterator it = headers.begin(); it != headers.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

//  ******** HANDLER ********

int Request::buildPath(DataConfig config) {
    if (requestRessource[requestRessource.size() - 1] == '/' || requestRessource.substr(1).find('/') != std::string::npos) {
        std::vector<Location> locations = config.getLocation();
        std::string requestedLocation = requestRessource.substr(0, requestRessource.find_last_of('/') + 1);
        for (std::vector<Location>::iterator it = locations.begin(); it != locations.end(); it++) {
            if (it->location.compare(requestedLocation) == 0) {
                if (config.getRoot().empty()) {
                    path = config.getRoot() + it->alias.substr(1);
                } else {
                    path = it->root;
                }
            }
        }
        if (path.empty()) {
            path = config.getRoot() + requestedLocation.substr(1);
        }
        return (0);
    }
    path = config.getRoot();
    return (0);
}

Response Request::handleRequest(DataConfig config) {
    int errorCode = validRequest(config);
    if (errorCode != 0) {
        Response response;
        if (errorCode == PERMANENTLY_MOVED) {
            response.setHeader("Location:", requestRessource + "/");
        }
        response.buildResponse(errorCode);
        // std::cout << response.getResponseEntity();
        return (response);
    }
    buildPath(config);
    std::cout << "path is " << path << std::endl;
    Response response;
    // if(this->requestMethod == "POST")
    // {
    //     std::cout << "POST\n";
    //     response = RequestMethod::POST(*this, config);
    // }
     if(this->requestMethod == "GET")
        response = RequestMethod::GET(*this, config);
    // std::cout << response.getResponseEntity();
    return response;
}