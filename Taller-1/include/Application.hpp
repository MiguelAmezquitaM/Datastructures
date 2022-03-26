#ifndef Application_hpp
#define Application_hpp

#include "User.hpp"

class Application {
private:
    List<User> users;

    User* userActive = nullptr;

    Chat* chatActive = nullptr;

    int option;

    bool running = true;

    List<User*> UsersNoMemberOfActiveChat();

    void WelcomeMenu();

    void RegisterMenu();

    void LoginMenu();

    void HomeMenu();

    void CreateChatMenu();

    void JoinToChatMenu();

    void ChatsMenu();

    void SelectChatMenu();

    void AddMemberToChatActiveMenu();

    void DeleteChatMenu();

    void ConversationMenu();

public:
    void start();
};

#endif