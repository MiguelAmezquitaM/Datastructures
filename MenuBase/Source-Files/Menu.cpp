#include "Menu.hpp"
#include <iostream>

using namespace menu;

using std::cout;
using std::cin;
using std::string;
using std::getline;

void menu::get_int(int& n) {
    string str;
    int num;
    bool passed = false;

    while (!passed) {
        passed = true;
        getline(cin, str, '\n');

        try {
            num = std::stoi(str);
        }
        catch (std::exception) {
            passed = false;
            cout << "Entrada invalida\n";
            cout << "Intentalo de nuevo: ";
        }
    }

    n = num;
}

void menu::get_float(float& n) {
    string str;
    float num;
    bool passed = false;

    while (!passed) {
        passed = true;
        getline(cin, str, '\n');

        try {
            num = std::stof(str);
        }
        catch (std::exception) {
            passed = false;
            cout << "Entrada invalida\n";
            cout << "Intentalo de nuevo: ";
        }
    }

    n = num;
}

void menu::get_string(string& str) {
    getline(cin, str, '\n');
}

void menu::prompt(string message, string& s) {
    cout << message << ": ";
    getline(cin, s, '\n');
}

void menu::prompt(string message, float& n) {
    cout << message << ": ";
    get_float(n);
}

void menu::prompt(string message, int& n) {
    cout << message << ": ";
    get_int(n);
}

void menu::clear_console() {
#if WINDOWS
    system("cls");
#else
    system("clear");
#endif
}

void menu::pause() {
    cout << "\nPresione una tecla para continuar...";
    cin.get();
}

