#include "../Utils.cpp"
#include <iostream>
#include <iomanip>

#define space setw(20)

using namespace std;

/*
 * la estructura computadora (Computer) tiene las siguientes
 * especificaciones:
 *
 * - Modelo: string
 * - Marca: string
 * - Capacidad de la memoria RAM (GB): int
 * - Capacidad de almacenamiento (GB): int
 * - Velocidad basica del reloj del procesador (GHz): float
 * - Identificador: int
 *
 * Los requerimientos de este modelo de datos son:
 *
 * 1. Llenar un conjunto de computadoras
 * 2. Listar las computadoras
 * 3. Buscar computadora por su numero de id
 * 4. Buscar computadoras con capacidad de almacenamiento minima de n
 * 5. Buscar computadoras con capacidad de memoria minima de n
 * 6. Ordenar la lista de diferentes formas
 */

struct Computer
{
    string trademark;
    string model;
    float clockSpeed;
    int memoryCapacity;
    int storageCapacity;
    int id;
};

void print_header_computer();
void print_row_computer(Computer pc);

int fillComputerList(Computer *list)
{
    int len;

    clearConsole();
    cout << "- How many computers do you want to add?  ";
    cin >> len;

    for (int i = 0; i < len; i++)
    {
        clearConsole();
        cout << "=========================\n";
        cout << "       Computer #" << i + 1 << "\n";
        cout << "=========================\n";

        cout << "\n- Input the trademark: ";
        cin >> list[i].trademark;

        cout << "\n- Input the model: ";
        cin >> list[i].model;

        cout << "\n- Input the clock speed: ";
        cin >> list[i].clockSpeed;

        cout << "\n- Input the memory capacity: ";
        cin >> list[i].memoryCapacity;

        cout << "\n- Input the storage capacity: ";
        cin >> list[i].storageCapacity;

        cout << "\n- Input the id: ";
        cin >> list[i].id;
    }

    return len;
}

void listComputers(Computer *list, int len)
{
    clearConsole();
    print_header_computer();

    for (int i = 0; i < len; i++)
        print_row_computer(list[i]);

    pause();
}

void print_header_computer()
{
    cout << "ID" << space << "Trademarker"
         << space << "Model" << space << "Memory Capacity"
         << space << "Storage Capacity" << space << "Clock speed" << endl
         << endl;
}

void print_row_computer(Computer pc)
{
    cout << pc.id << space << pc.trademark
         << space << pc.model << space << pc.memoryCapacity
         << space << pc.storageCapacity << space << pc.clockSpeed << endl;
}

void SearchComputerById(Computer *list, int len)
{
    int id = -1;
    int index;

    clearConsole();
    cout << "Input id: ";
    cin >> id;

    for (int i = 0; i < len; i++)
        if (list[i].id == id)
            index = i;

    clearConsole();
    if (index >= 0)
    {
        print_header_computer();
        print_row_computer(list[index]);
        cout << "\n\n";
    }
    else
        cout << "Not found 404\n";

    pause();
}

void sortListOfComputers(Computer *list, int len, string specific, bool order)
{
    if (order)
    {

    }
}
