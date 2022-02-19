#include "./model/Computer.cpp"

const char header[] = "=================================\n      Selecciona una opcion\n=================================\n\n";

int main_menu_body()
{
    int opc;

    clearConsole();
    cout << header;

    cout << "1. Fill list of computers\n";
    cout << "2. List computers\n";
    cout << "3. Search computer by ID\n";
    cout << "4. Filters\n";
    cout << "5. Sort by\n";
    cout << "6. Exit\n\n";

    cout << "Selecciona una opcion: ";
    cin >> opc;

    return opc;
}

int filters_menu_body()
{
    int opc;
    clearConsole();
    cout << header;

    cout << "1. Ordenar por marca\n";
    cout << "2. Ordenar por capacidad de memoria\n";
    cout << "3. Ordenar por capacidad de almacenamiento\n";
    cout << "4. Ordenar por velocidad del reloj\n";

    cout << "Selecciona una opcion: ";
    cin >> opc;

    return opc;
}

void filters_menu(Computer *list, int len)
{
    int opc = filters_menu_body();

    switch (opc)
    {
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    case 4:

        break;

    default:
        break;
    }
}

void main_menu(Computer *list)
{
    bool run = true;
    int opc;
    int len = 10;

    while (run)
    {
        opc = main_menu_body();
        switch (opc)
        {
        case 1:
            len = fillComputerList(list);
            break;
        case 2:
            listComputers(list, len);
            break;
        case 3:
            SearchComputerById(list, len);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            run = false;
            break;
        default:
            break;
        }
    }
}