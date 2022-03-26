#include "Application.hpp"
#include "Utils.hpp"

using std::cout;
using std::cin;
using std::string;

const string HEADER() {
    string header = "";

    header += "===========================\n";
    header += "   Selecciona una opcion\n";
    header += "===========================\n";

    return header;
}

void Application::WelcomeMenu() {
    clear_console();
    cout << HEADER() << "\n";

    cout << "1. Crear un nuevo usuario\n";
    cout << "2. Iniciar sesion\n";
    cout << "3. Salir\n";

    cout << "\n-> ";

    get_int(option, 1, 3);

    switch (option) {
    case 1:
        RegisterMenu();
        break;
    case 2:
        LoginMenu();
        break;
    case 3:
        running = false;
        break;
    }
}

void Application::RegisterMenu() {
    User newUser;
    string username;

    clear_console();
    cout << "=====================\n";
    cout << "       Sign up\n";
    cout << "=====================\n\n";

    cout << "Nombre de usuario: ";
    get_line(username, 4);

    newUser.setName(username);
    users.append(newUser);

    clear_console();
    cout << "Usuario creado!\n";
    pause();
}

void Application::LoginMenu() {
    clear_console();
    cout << "=====================\n";
    cout << "       Sign in\n";
    cout << "=====================\n\n";

    cout << "Seleccione el usuario\n\n";

    users.forEach([](User& user, int i) {
        cout << i + 1 << ". " << user.getName() << "\n";
    });

    cout << "\n-> ";
    get_int(option, 1, users.length());

    userActive = &users[option - 1];
}

void Application::HomeMenu() {
    clear_console();
    cout << HEADER() << "\n";

    cout << "1. Crear nuevo chat\n";
    cout << "2. Ver todos mis chats\n";
    cout << "3. Seleccionar un chat\n";
    cout << "4. Ver chat con mensaje mas reciente\n";
    cout << "5. Eliminar un chat\n";
    cout << "6. Cerrar sesion\n";

    cout << "\n-> ";
    get_int(option, 1, 6);

    switch (option) {
    case 1:
        CreateChatMenu();
        break;
    case 2:
        ChatsMenu();
        break;
    case 3:
        SelectChatMenu();
        break;
    case 4:
        chatActive = userActive->getLastChat();
        break;
    case 5:
        DeleteChatMenu();
        break;
    case 6:
        userActive = nullptr;
        clear_console();
        cout << "Cession cerrada!\n";
        pause();
        break;
    }
}

void Application::CreateChatMenu() {
    string chatname;

    clear_console();
    cout << "=========================\n";
    cout << "       Creando Chat\n";
    cout << "=========================\n\n";

    cout << "Nombre del chat: ";
    get_line(chatname, 4);

    userActive->createChat()->setName(chatname);

    clear_console();
    cout << "Chat creado!\n";
    pause();
}

void Application::ChatsMenu() {
    clear_console();
    cout << "====================\n";
    cout << "    Chats creados\n";
    cout << "====================\n\n";

    if (userActive->getAllChats().empty()) {
        cout << "No tienes chats creados\n";
    }
    else {
        userActive->getAllChats().forEach([](Chat*& chat, int i) {
            cout << i + 1 << ". " << chat->getName() << "\n";
            });
    }

    pause();
}

void Application::SelectChatMenu() {
    clear_console();
    cout << "=======================\n";
    cout << "    Seleccionar Chat\n";
    cout << "=======================\n\n";

    auto ChatList = userActive->getAllChats();

    if (ChatList.empty()) {
        cout << "No tienes chats creados\n";
        pause();
        return;
    }
    else {
        ChatList.forEach([](Chat*& chat, int i) {
            cout << i + 1 << ". " << chat->getName() << "\n";
            });
    }

    cout << "\nA que chat desea entrar ?\n";
    cout << "-> ";
    get_int(option, 1, ChatList.length());

    chatActive = ChatList[option - 1];

    clear_console();
    cout << "Chat seleccionado!\n";
    pause();
}

void Application::ConversationMenu() {
    string message;
    List<User*> noMembers;
    auto chatActiveT = chatActive;

    clear_console();
    cout << "====================\n";
    cout << "      Mensajes\n";
    cout << "====================\n\n";

    chatActive->showAllMessages();

    cout << "\nOpciones: \n";
    cout << "1. Escribir mensaje\n";
    cout << "2. Agregar al chat\n";
    cout << "3. Salir del chat\n\n";
    cout << "-> ";
    get_int(option, 1, 3);

    switch (option) {
    case 1:
        clear_console();
        cout << "Mensaje: ";
        get_line(message, 1);
        chatActive->sendMessage(userActive, message);
        cout << "\n Enviado!";
        pause();
        break;
    case 2:
        AddMemberToChatActiveMenu();
        break;
    case 3:
        chatActive = nullptr;
        break;
    }
}

List<User*> Application::UsersNoMemberOfActiveChat() {
    auto chatActiveT = chatActive;
    List<User*> noMembers;

    users.forEach([&chatActiveT, &noMembers](User& user, int i) {
        bool isMember = user.isMember(chatActiveT);

        if (!isMember)
            noMembers.append(&user);
        });

    return noMembers;
}

void Application::AddMemberToChatActiveMenu() {
    auto chatActiveT = chatActive;
    List<User*> noMembers = UsersNoMemberOfActiveChat();

    clear_console();
    cout << "Seleccione el usuario a agregar\n\n";

    if(noMembers.empty()) {
        cout << "No hay usuarios para agregar\n";
        pause();
        return;
    }

    noMembers.forEach([](User*& user, int i) {
        cout << i + 1 << ". " << user->getName() << "\n";
    });

    cout << "\n-> ";
    get_int(option, 1, noMembers.length());

    chatActive->addMember(noMembers[option - 1]);

    clear_console();
    cout << "Agregado correctamente!\n";
    pause();
}

void Application::DeleteChatMenu() {
    auto chats = userActive->getAllChats();
    clear_console();
    cout << "==========================\n";
    cout << "      Eliminar chat\n";
    cout << "==========================\n\n";

    if(chats.empty()) {
        cout << "No hay chats para eliminar\n";
        pause();
        return;
    }

    chats.forEach([](Chat*& chat, int i) {
        cout << i + 1 << ". " << chat->getName() << "\n";
    });

    cout << "\n-> ";
    get_int(option, 1, chats.length());
    userActive->deleteChatFromAllMembers(chats[option - 1]);

    clear_console();
    cout << "Chat eliminado!\n";
    pause();
}

void Application::start() {
    while (running) {
        if (userActive == nullptr) {
            WelcomeMenu();
        }
        else if (userActive != nullptr && chatActive == nullptr) {
            HomeMenu();
        }
        else {
            ConversationMenu();
        }
    }
}