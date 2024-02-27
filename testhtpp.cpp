#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> // Include this header for the inet_addr function
#include <string>

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error: Unable to create server socket" << std::endl;
        return 1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888);
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Listen on all available interfaces

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        std::cerr << "Error: Unable to bind to port" << std::endl;
        close(serverSocket); // Close the server socket in case of error
        return 1;
    }

    if (listen(serverSocket, 5) < 0) {
        std::cerr << "Error: Unable to listen on socket" << std::endl;
        close(serverSocket); // Close the server socket in case of error
        return 1;
    }

    std::cout << "Server is listening on port 8888" << std::endl;

    // Accept connections and handle them
    while (true) {
        int clientSocket = accept(serverSocket, nullptr, nullptr);
        if (clientSocket < 0) {
            std::cerr << "Error: Unable to accept connection" << std::endl;
            close(serverSocket); // Close the server socket in case of error
            return 1;
        }

        // Send a simple HTTP response
        std::string httpResponse = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n";

        // Your HTML content
        std::string htmlContent = "<html><head><title>Simple HTTP Server</title></head>";
        htmlContent += "<body><h1>Hello from your HTTP server!</h1></body></html>";

        // Calculate the length of the HTML content
        std::string contentLengthHeader = "Content-Length: " + std::to_string(htmlContent.length()) + "\r\n";

        // Add the Content-Length header to the response
        httpResponse += contentLengthHeader;
        httpResponse += "\r\n"; // Add an extra newline to separate headers from body
        httpResponse += htmlContent;

        // Send the response
        send(clientSocket, httpResponse.c_str(), httpResponse.length(), 0);

        // Close the client socket when done
        close(clientSocket);
    }

    // Close the server socket (not reached in this example)
    close(serverSocket);
    return 0;
}
