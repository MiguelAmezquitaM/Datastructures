#include "User.hpp"

Chat* User::createChat() {
    auto chat = new Chat;

    chat->addMember(this);
    chat->setName(getName());

    return chat;
}

void User::putFirst(Chat* chat) {
    Stack<Chat*> temp;
    Chat* tempChat = nullptr;

    while (!chats.empty()) {
        tempChat = chats.get();

        if (chat == tempChat) {
            chats.remove();
            break;
        }

        temp.insert(tempChat);
        chats.remove();
    }

    while (!temp.empty()) {
        chats.insert(temp.get());
        temp.remove();
    }

    if (tempChat != nullptr)
        chats.insert(tempChat);
}

void User::deleteChat(Chat* chat) {
    Stack<Chat*> temp;
    Chat* tempChat = nullptr;

    while (!chats.empty()) {
        tempChat = chats.get();

        if (chat == tempChat) {
            chats.remove();
            break;
        }

        temp.insert(tempChat);
        chats.remove();
    }

    while (!temp.empty()) {
        chats.insert(temp.get());
        temp.remove();
    }
}

void User::deleteChatFromAllMembers(Chat* chat) {
    chat->getMembers().forEach([&chat](User*& user, int i) {
        user->deleteChat(chat);
    });

    chat->removeAllMembers();

    delete chat;
}

Chat* User::getLastChat() {
    return chats.get();
}

List<Chat*> User::getAllChats() {
    List<Chat*> allChats;
    Stack<Chat*> stackTemp;

    while (!chats.empty()) {
        allChats.append(chats.get());
        stackTemp.insert(chats.get());
        chats.remove();
    }

    while (!stackTemp.empty()) {
        chats.insert(stackTemp.get());
        stackTemp.remove();
    }

    return allChats;
}

bool User::isMember(Chat* chat) {
    bool IsMember = false;
    Stack<Chat*> stackTemp;

    while (!chats.empty()) {
        if (chats.get() == chat) {
            IsMember = true;
            break;
        }

        stackTemp.insert(chats.get());
        chats.remove();
    }

    while (!stackTemp.empty()) {
        chats.insert(stackTemp.get());
        stackTemp.remove();
    }

    return IsMember;
}


void User::addToChat(Chat* chat) {
    chats.insert(chat);
}
