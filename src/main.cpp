#include <iostream>

#include "WebServer/Receiver.hpp"

webServer::Receiver createWebServerReceiver() {
    using namespace webServer;
    std::string ipAddress = "127.0.0.1";
    Receiver receiver = Receiver(ipAddress, 8080);
    int result = receiver.startServer();
    if (result != 0) {
        std::cout << "Could not open the receiver socket, exiting...\n";
        receiver.~Receiver();
        exit(1);
    }
    return receiver;
}

int removeWebServerReceiver() {

}

int main() {
    std::cout << "Hello, World!" << std::endl;
    createWebServerReceiver();
    return 0;
}
