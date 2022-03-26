#ifndef Message_hpp
#define Message_hpp

#include <iostream>

class Message {
private:
    std::string message;
    std::string emiter;

public:
    Message(std::string message, std::string emiter)
        : message(message), emiter(emiter) {
    }

    Message() = default;

    std::string getMessage() { return message; }
    std::string getEmiter() { return emiter; }
    void print() { std::cout << emiter << ": " << message << "\n"; }
};


#endif