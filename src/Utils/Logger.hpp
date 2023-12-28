//
// Created by Joshua Wong on 28/12/2023.
//

#ifndef SANDBOX_LOGGER_HPP
#define SANDBOX_LOGGER_HPP

#include <string>

namespace Utils {
    class Logger {
    public:
        Logger();
        ~Logger();

        void log(std::string &message);

    private:

    };
}


#endif //SANDBOX_LOGGER_HPP
