//
// Created by Joshua Wong on 28/12/2023.
//

#include "Receiver.hpp"

namespace webServer {
    Receiver::Receiver(std::string &ipAddress, const int port) {
        mSocket = -1;
        mIpAddress = ipAddress;
        mPort = port;
        mIncomingMessage = 0;
        mSocketAddress = sockaddr_in();
        mSocketAddress.sin_family = AF_INET;
        mSocketAddress.sin_port = htons(port);
        mSocketAddress.sin_addr.s_addr = inet_addr(mIpAddress.c_str());
        mSocketLen = sizeof(mSocketAddress);
        mServerMessage = "";
    }

    Receiver::~Receiver() {
        close(mSocket); // Closes the file descriptor for the socket.

        exit(0);
    }

    int Receiver::startServer() {
        // Create a socket with the following parameters using the Linux socket API
        // domain = AF_INET (IPv4 protocol by the AF_INET domain)
        // type = SOCK_STREAM (for full duplex byte streams)
        // protocol = 0 (
        mSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (mSocket < 0) {
            std::cout << "Failed to create socket\n";
            return 1;
        }
        std::cout << "Socket receiver created\n";
        if (bind(mSocket, (sockaddr *)&mSocketAddress, mSocketLen) < 0) {
            std::cout << "Socket receiver failed to bind to IP address: " + mIpAddress + ", Port: " + std::to_string(mPort) + "\n";
            return 1;
        }
        std::cout << "Socket receiver bound to IP address: " + mIpAddress + ", Port: " + std::to_string(mPort) + "\n";
        return 0;
    }
}

