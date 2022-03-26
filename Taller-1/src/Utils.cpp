#include <iostream>
#include <string>

using std::string;
using std::exception;
using std::getline;
using std::stoi;
using std::cin;
using std::cout;


void clear_console() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void get_int(int& a) {
    string temp;
    bool passed = false;

    while (!passed) {
        getline(cin, temp, '\n');
        passed = true;

        try {
            a = stoi(temp);
        }
        catch (exception e) {
            cout << "Entrada invalida!\n";
            cout << "Intentalo de nuevo: ";
            temp = false;
        }
    }
}

void get_int(int& a, int min, int max) {
    a = min - 1;

    while (a < min || a > max) {
        get_int(a);

        if (a < min || a > max) {
            cout << "Entrada invalida!\n";
            cout << "Intentalo de nuevo: ";
        }
    }
}

void get_line(string& a) {
    getline(cin, a, '\n');
}

void get_line(string& a, int min) {
    a = "";
    while (a.length() < min) {
        getline(cin, a, '\n');

        if (a.length() < min) {
            cout << "El texto debe ser de minimo " << min << " caracteres\n";
            cout << "Intentalo de nuevo: ";
        }
    }
}

void pause() {
    cout << "\nPresione una tecla para continuar...\n";
    cin.get();
}