#include "RequestMethods.hpp"
#include "Response.hpp"
#include <fstream>
#include <sstream>
#include <vector>

void buildResponseWithFile(Response& response, std::string filename, unsigned int code) {
    std::ostringstream ss;
    std::ifstream file(filename);
    if (!(code >= 200 && code <= 208)) {
        response.buildResponse(code);
        return ;
    } else {
        if (file.fail()) {
                response.buildResponse(NOT_FOUND);
                return ;
            } else {
                ss << file.rdbuf();
                response.setContentType("index.html");
                response.setContentLength(ss.str().size());
                response.setResponseBody(ss.str());
                response.buildResponse(OK);
                return ;
            }
    }
}

int checkIfLocationExists(std::vector<Location> locations, std::string requestedRessource) {
    for (size_t i = 0; i < locations.size(); i++) {
        if (locations[i].location.compare(requestedRessource) == 0)
            return (i);
    }
    return (-1);
}

Response RequestMethod::GET(Request& request, DataConfig config) {
    std::string requestedRessource = request.getRequestRessource();
    Response response;
    if (requestedRessource.compare("/") == 0) {
        buildResponseWithFile(response, config.getIndex(), OK);
        return (response);
    } else if (requestedRessource[requestedRessource.size() - 1] == '/') {
        std::vector<Location> locations = config.getLocation();
        int index = checkIfLocationExists(locations, requestedRessource);
        if (index != -1) {
            if (locations[index].methods.get == 0) {
                buildResponseWithFile(response, "", METHOD_NOT_ALLOWED);
                return (response);
            }
            buildResponseWithFile(response, locations[index].index, OK);
            return (response);
        } else {
            buildResponseWithFile(response, "", NOT_FOUND);
            return (response);
        }
    } else {
        buildResponseWithFile(response, requestedRessource.substr(1), OK);
        return (response);
    }
    return (response);
}