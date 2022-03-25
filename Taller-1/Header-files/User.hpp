#ifndef User_hpp
#define User_hpp


#include "Message.hpp"
#include "Pila.hpp"
#include <iostream>

class User {
    std::string name;
    Pila<Message> messages;

public:

    User(std::string name) : name(name) {};

    void sendMessage(User* destiny, std::string message);
    void receiveMessage(Message message);
    void printLastMessage();
    void printAllMessages();
    void deleteAllMessages();
    void invertStackMessages();
    
    std::string get_name() { return name; }
};

#endif