#include "Bank.hpp"
#include "Menu.hpp"

using namespace bank;
using namespace menu;
using std::string;

string get_header();

void input_client(Bank&);
void attend_client(Bank&);
void print_clients(Bank&);
void print_balance(Bank&);
void delete_by_id(Bank&);

auto main() -> int {
    Bank bank;
    int opt = 0;
    Choices<int> main_menu;

    main_menu = {
        get_header(),
        {
            {1, "Ingresar cliente"},
            {2, "Atender cliente"},
            {3, "Listar clientes pendientes"},
            {4, "Eliminar por ID"},
            {5, "Ver balance"},
            {6, "Salir"}
        }
    };

    while (opt != 6) {
        clear_console();

        opt = promptChoices(main_menu);

        switch (opt) {
        case 1:
            input_client(bank);
            break;

        case 2:
            attend_client(bank);
            break;

        case 3:
            print_clients(bank);
            break;

        case 4:
            delete_by_id(bank);
            break;

        case 5:
            print_balance(bank);
            break;

        default:
            break;
        }
    }

    return EXIT_SUCCESS;
}


string get_header() {
    string a = "=================================\n";
    string b = "      Seleccione una opcion\n";
    string c = "=================================";
    return a + b + c;
}

void input_client(Bank& bank) {
    Client client;
    Choices<Action> action;
    Choices<Priority> priority;

    action = { "¿Que desea hacer?",
    {
        {retirement, "Retirar"},
        {consignment, "Consignmet"}
    } };

    priority = { "Cual es su rango de prioridad?",
    {
        {normal, "Normal"},
        {priviliged, "Priviliged"}
    } };

    clear_console();
    prompt("Nombre", client.name);
    clear_console();
    client.action = promptChoices(action);
    clear_console();
    prompt("Cantidad", client.value);
    clear_console();
    client.priority = promptChoices(priority);
    clear_console();
    prompt("ID", client.id);

    bank.input(client);
}

void attend_client(Bank& bank) {
    clear_console();
    bank.attend();
    pause();
}

void print_clients(Bank& bank) {
    clear_console();
    bank.print_queue();
    pause();
}

void delete_by_id(Bank& bank) {
    int id;
    clear_console();
    prompt("Inserte el ID", id);
    bank.deleteById(id);
    pause();
}

void print_balance(Bank& bank) {
    clear_console();
    bank.print_balance();
    pause();
}
