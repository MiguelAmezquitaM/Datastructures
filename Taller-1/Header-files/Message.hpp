#ifndef Usuario_hpp
#define Usuario_hpp

#include <iostream>

struct Message {
    std::string message;
    std::string emiter;

    Message(std::string message, std::string emiter)
        : message(message), emiter(emiter) {
    }
};

#endif