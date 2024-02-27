#include <iostream>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h> // Include this header for the inet_addr function

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0) {
        std::cerr << "Error: Unable to create server socket" << std::endl;
        return 1;
    }

    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8888);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Listen on localhost

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

        // Handle the client connection (send/receive data)
        // Your code to handle client connections goes here

        // Close the client socket when done
        close(clientSocket);
    }

    // Close the server socket (not reached in this example)
    close(serverSocket);
    return 0;
}
