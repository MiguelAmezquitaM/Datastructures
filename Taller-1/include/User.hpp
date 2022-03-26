#ifndef User_hpp
#define User_hpp

#include <iostream>
#include "Chat.hpp"

class Chat;

class User {
private:
    std::string name;
    Stack<Chat*> chats;

public:
    User(std::string name) : name(name) {}

    User() = default;

    Chat* createChat();

    Chat* getLastChat();

    Chat* getChatByName();

    void putFirst(Chat*);

    void setName(std::string name) { this->name = name; }

    bool isMember(Chat*);

    void addToChat(Chat*);

    void deleteChat(Chat*);

    void deleteChatFromAllMembers(Chat*);

    List<Chat*> getAllChats();

    std::string getName() { return name; }

};


#endif