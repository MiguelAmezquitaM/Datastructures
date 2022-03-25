#ifndef Application_hpp
#define Application_hpp

#include <iostream>
#include "Lista.hpp"
#include "User.hpp"
#include "Menu.hpp"

class Application {
    Lista<User> listaDeUsuarios;
    User* actualUser = NULL;

public:
    void registerUser(std::string name);
    void deleteUser(std::string name);
    void sendMessage();
    void printUsers();

    int NumberOfUsers();

    User* getUser(int i);
    User* getActualUser() { return actualUser; };

    void start();
};

#endif