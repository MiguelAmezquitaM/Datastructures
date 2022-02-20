#pragma once

#include "Menu.hpp"
#include "Utility.hpp"

using namespace pcl;
using namespace utl;
using namespace std;
using namespace menu;

#define h1 "=================================\n"
#define h2 "      Selecciona una opcion\n"
#define h3 "=================================\n\n"

void menu::main_menu(ComputerList *listOfComputers)
{
    bool run = true;
    int opc;
    int len = listOfComputers->len;

    while (run)
    {
        opc = main_menu_body();
        switch (opc)
        {
        case 1:
            len = fillComputerList(listOfComputers);
            listOfComputers->len += len;
            break;
        case 2:
            listOfComputers->print();
            break;
        case 3:
            searchComputerById(listOfComputers);
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

int menu::main_menu_body()
{
    int opc;

    clearConsole();
    print_header();

    cout << "1. Fill list of computers (or append)\n";
    cout << "2. List computers\n";
    cout << "3. Search computer by ID\n";
    cout << "4. Filters\n";
    cout << "5. Sort by\n";
    cout << "6. Exit\n\n";

    cout << "Selecciona una opcion: ";
    cin >> opc;

    return opc;
}

int menu::fillComputerList(ComputerList *listOfComputers)
{
    int len;
    int alen = listOfComputers->len;
    pcp::Computer *list = listOfComputers->list;

    clearConsole();
    cout << "- How many computers do you want to add?  ";
    cin >> len;

    for (int i = alen; i < len + alen; i++)
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

void menu::searchComputerById(ComputerList *listOfComputers)
{
    int id;
    int index;

    clearConsole();
    cout << "Input id: ";
    cin >> id;

    index = listOfComputers->searchElementByID(id);

    listOfComputers->print(index);
}

void menu::print_header()
{
    cout << h1 << h2 << h3;
}
