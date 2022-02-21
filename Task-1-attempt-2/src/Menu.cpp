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

// Complements main menu
inline int main_menu_body();

// interface to agregate data from console
inline int fillComputerList(ComputerList *);

// interface to search computers from console
inline void searchComputerById(ComputerList *);

// interfaces to sort list
inline void sortby_menu(ComputerList *);
inline int sortby_menu_body_1();
inline int sortby_menu_body_2();

// setting for filters
inline void filter_menu(ComputerList *listOfComputers);

// **
inline void print_header();

// implementations ------------------------------------------------

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
            sortby_menu(listOfComputers);
            break;
        case 6:
            run = false;
            break;
        default:
            break;
        }
    }
}

inline int main_menu_body()
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

inline int fillComputerList(ComputerList *listOfComputers)
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

inline void searchComputerById(ComputerList *listOfComputers)
{
    int id;
    int index;

    clearConsole();
    cout << "Input id: ";
    cin >> id;

    index = listOfComputers->searchElementByID(id);
    listOfComputers->print(index);
}

inline void filter_menu(ComputerList *listOfComputers)
{
}

inline void sortby_menu(ComputerList *listOfComputers)
{
    int opc;
    int mode;

    opc = sortby_menu_body_1();
    if (opc == 6)
        return;

    mode = sortby_menu_body_2();
    if (mode == 3)
        return;

    switch (opc)
    {
    case 1:
        listOfComputers->sortByField<pcf::StringFields>(pcf::trademark, mode == 1 ? smallesto : biggesto);
        break;
    case 2:
        listOfComputers->sortByField<pcf::FloatFields>(pcf::clockSpeed, mode == 1 ? smallesto : biggesto);
        break;
    case 3:
        listOfComputers->sortByField<pcf::IntFields>(pcf::memoryCapacity, mode == 1 ? smallesto : biggesto);
        break;
    case 4:
        listOfComputers->sortByField<pcf::IntFields>(pcf::storageCapacity, mode == 1 ? smallesto : biggesto);
        break;
    case 5:
        listOfComputers->sortByField<pcf::IntFields>(pcf::id, mode == 1 ? smallesto : biggesto);
        break;
    default:
        break;
    }
}

inline int sortby_menu_body_1()
{
    int opc = 0;

    while (opc < 1 || opc > 5)
    {
        clearConsole();
        print_header();
        cout << "You want to sort the list by...\n\n";

        cout << "1. Trademark\n";
        cout << "2. Clock speed\n";
        cout << "3. Memory capacity\n";
        cout << "4. Storage capacity\n";
        cout << "5. ID\n";
        cout << "6. Cancel\n\n";

        cout << "Option: ";
        cin >> opc;
    }

    return opc;
}

inline int sortby_menu_body_2()
{
    int mode = 0;
    while (mode < 1 || mode > 3)
    {
        clearConsole();
        print_header();
        cout << "Select the mode of sort...\n\n";

        cout << "1. Smallest to largest\n";
        cout << "2. Largest to Smallest\n";
        cout << "3. Cancel\n\n";

        cout << "Option: ";
        cin >> mode;
    }
    return mode;
}

inline void print_header()
{
    cout << h1 << h2 << h3;
}
