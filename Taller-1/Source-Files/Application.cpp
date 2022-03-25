#include "Application.hpp"

using std::string;
using std::cout;
using std::cin;

void Application::registerUser(string name) {
    User newUser(name);
    listaDeUsuarios.insert(newUser);
}

void Application::deleteUser(string name) {
    int index = -1;
    for (int i = 0; i < listaDeUsuarios.length(); i++)
        if (listaDeUsuarios.get(i)->get_name() == name)
            index = i;

    if (index != -1)
        listaDeUsuarios.remove(index);

    else throw std::logic_error("No existe el usuario");
}

void Application::printUsers() {
    listaDeUsuarios.forEach([](User* user, int v) {
        cout << v + 1 << ". " << user->get_name() << "\n";
        });
}

int Application::NumberOfUsers() {
    return listaDeUsuarios.length();
}

User* Application::getUser(int i) {
    return listaDeUsuarios.get(i);
}

int homeMenu() {
    Choice<int> ListOptions[] = {
        {1, "Crear nuevo usuario"},
        {2, "Iniciar sesion"},
        {3, "Salir"},
    };

    Choices<int> options = {
        "Bienvenido... Seleccione una de las opciones\n",
        3,
        ListOptions
    };

    return promptChoices(options);
}

string getUsername() {
    string name;

    clear_console();

    cout << "Nombre de usuario: ";
    get_line(name);

    return name;
}

User* signInUser(Application* app) {
    int index = -1;
    clear_console();

    if (app->NumberOfUsers() == 0) return NULL;

    app->printUsers();

    get_int_interval(index, 1, app->NumberOfUsers());

    return app->getUser(index - 1);
}

int userMenu() {
    Choice<int> ListOptions[] = {
        {1, "Enviar mensaje"},
        {2, "Ver ultimo mensaje"},
        {3, "Ver todos los mensajes"},
        {4, "Borrar todos los mensajes"},
        {5, "Invertir la pila de mensajes"},
        {6, "Cerrar sesion"},
    };

    Choices<int> options = {
        "Que operacion desea realizar? \n",
        6,
        ListOptions
    };

    return promptChoices(options);
}

void sendMessageMenu(Application* app) {
    string message;
    User* destiny;
    int userId = -1;

    clear_console();
    cout << "Seleccione el destinatario del mensaje\n\n";
    app->printUsers();
    get_int_interval(userId, 1, app->NumberOfUsers());

    destiny = app->getUser(userId - 1);

    clear_console();

    cout << "Escriba su mensaje: ";
    get_line(message);

    app->getActualUser()->sendMessage(destiny, message);
}

void Application::start() {
    User* user;
    bool finished = false;
    int opc;

    while (!finished) {
        if (actualUser == NULL) {
            opc = homeMenu();

            switch (opc) {
            case 1:
                registerUser(getUsername());
                break;
            case 2:
                user = signInUser(this);

                if (user != NULL)
                    actualUser = user;
                break;
            case 3:
                finished = true;
                break;
            }
        }
        else {
            opc = userMenu();

            switch (opc) {
            case 1:
                sendMessageMenu(this);
                break;

            case 2:
                clear_console();
                actualUser->printLastMessage();
                cin.get();
                break;

            case 3:
                clear_console();
                actualUser->printAllMessages();
                cin.get();
                break;

            case 4:
                clear_console();
                actualUser->deleteAllMessages();
                cout << "Mensajes elimnados";
                cin.get();
                break;

            case 5:
                clear_console();
                actualUser->invertStackMessages();
                cout << "Cola de mensajes invertida";
                cin.get();
                break;

            case 6:
                actualUser = NULL;
                break;
            }
        }
    }
}
