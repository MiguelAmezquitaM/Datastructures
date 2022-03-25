#include "Menu.hpp"

using std::cout;

void get_int(int& n) {
    std::string temp;
    bool passed = false;

    while (!passed) {
        getline(std::cin, temp, '\n');
        passed = true;

        try {
            n = stoi(temp);
        }
        catch (std::exception e) {
            passed = false;
        }
    }
}

void get_int_interval(int& n, int min, int max) {
    while (min > n || max < n) {
        cout << "\n-> ";
        get_int(n);
    }
}

void get_line(std::string& str) {
    std::getline(std::cin, str, '\n');
}

void clear_console() {
#ifdef _WIN32 
    system("cls");
#else
    system("clear");
#endif
}