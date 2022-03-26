#ifndef Chat_hpp
#define Chat_hpp

#include "structs/Stack.hpp"
#include "User.hpp"
#include "Message.hpp"

class User;

class Chat {
private:
    std::string name;
    Stack<Message> stackMessages;
    List<User*> members;

    void updateMembers();
public:

    void addMember(User* user);

    void removeAllMembers();

    List<User*> getMembers();

    void sendMessage(User* emiter, std::string message);

    void showLastMessage();

    void showAllMessages();

    void invertStackMessages();

    void setName(std::string name) { this->name = name; }

    std::string getName() { return name; }
};

#endif