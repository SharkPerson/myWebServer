//
// Created by Joshua Wong on 28/12/2023.
//
// Web Socket that receives incoming HTTP packets and decodes them before passing it to the processor.
//
//
//

#ifndef SANDBOX_RECEIVER_HPP
#define SANDBOX_RECEIVER_HPP

#include <iostream>
#include <unistd.h>
#include <arpa/inet.h>

#include "sys/socket.h"

namespace webServer {
    class Receiver {
    public:
        // Default Constructor
        Receiver(std::string &ipAddress, int port);
        // Default Destructor
        ~Receiver();

        int startServer();
        void closeServer();

    private:
        int mSocket; // The file descriptor of a socket?

        std::string mIpAddress;
        int mPort;
        long mIncomingMessage;
        struct sockaddr_in mSocketAddress;
        uint32_t mSocketLen;
        std::string mServerMessage;
    };
}

#endif //SANDBOX_RECEIVER_HPP
