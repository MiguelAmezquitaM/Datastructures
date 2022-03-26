#include "Chat.hpp"
#include "structs/Queue.hpp"

using std::cout;
using std::string;

void Chat::addMember(User* user) {
    members.append(user);
    user->addToChat(this);
}

void Chat::removeAllMembers() {
    while(!members.empty())
        members.removeBegin();
}

List<User*> Chat::getMembers() {
    return members;
}

void Chat::sendMessage(User* user, string message) {
    Message newMessage(message, user->getName());

    stackMessages.insert(newMessage);
    updateMembers();
}

void Chat::updateMembers() {
    members.forEach([this](User*& user, int) {
        user->putFirst(this);
    });
}

void Chat::showLastMessage() {
    if (stackMessages.empty()) cout << "No hay mensajes\n";
    else stackMessages.get().print();
}

void Chat::showAllMessages() {
    Message tempMessage;
    Stack<Message> tempStack;

    while (!stackMessages.empty()) {
        tempMessage = stackMessages.get();

        tempMessage.print();

        tempStack.insert(tempMessage);
        stackMessages.remove();
    }
    while (!tempStack.empty()) {
        stackMessages.insert(tempStack.get());
        tempStack.remove();
    }
}

void Chat::invertStackMessages() {
    Queue<Message> tempQueue;

    while (!stackMessages.empty()) {
        tempQueue.append(stackMessages.get());
        stackMessages.remove();
    }
    while (!tempQueue.empty()) {
        stackMessages.insert(tempQueue.get());
        tempQueue.remove();
    }
}