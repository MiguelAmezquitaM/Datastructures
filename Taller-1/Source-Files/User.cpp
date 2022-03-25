#include "User.hpp"

void User::sendMessage(User* destiny, std::string message) {
    Message newMessage(message, name);
    destiny->receiveMessage(newMessage);
}

void User::receiveMessage(Message message) {
    messages.insertar(message);
}

void User::printLastMessage() {
    if (!messages.empty())
        std::cout << messages.get().emiter << ": " << messages.get().message << "\n";
}

void User::printAllMessages() {
    Pila<Message> temp;
    Message messageTemp("", "");

    while (!messages.empty()) {
        messageTemp = messages.get();
        std::cout << messageTemp.emiter << ": " << messageTemp.message << "\n";

        temp.insertar(messageTemp);
        messages.eliminar();
    }
    while (!temp.empty()) {
        messages.insertar(temp.get());
        temp.eliminar();
    }
}

void User::deleteAllMessages() {
    while (!messages.empty()) {
        messages.eliminar();
    }
}


void User::invertStackMessages() {
    Pila<Message> pila1;
    Pila<Message> pila2;
    while (!messages.empty()) {
        pila1.insertar(messages.get());
        messages.eliminar();
    }

    while (!pila1.empty()) {
        pila2.insertar(pila1.get());
        pila1.eliminar();
    }

    while(!pila2.empty()) {
        messages.insertar(pila2.get());
        pila2.eliminar();
    }
}

